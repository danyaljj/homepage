#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <winbgim.h>
#include <math.h>
#include <iomanip>
//#include<stdlib>
//#include <stdio>

using namespace std;
long double e[3];
long double maximum;
#define ZARIB 10000
#define witgh 800
#define height 600
long int distance2 (int x1, int y1, int x2, int y2 )
{
    return pow(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)),0.50);
}

long double superPos (int x, int xPrime, int yPrime, int q1, int q2, int Q, int X, int Y)
{
    if( (sqrt(distance2(X, Y, xPrime, yPrime)) == 0) ||  (sqrt(distance2(X, Y, witgh-x, height))==0 ) || (sqrt(distance2(X, Y, witgh+x, height))==0) ) ///// determine not to divide by zero
    {
        return 0;
    }

    e[1] = ( Q*ZARIB /distance2(X, Y, xPrime, yPrime) ) * (X-xPrime)/ sqrt(distance2(X, Y, xPrime, yPrime))+
           (q2*ZARIB /distance2(X, Y, witgh/2-x, height/2) ) * (X+x-witgh/2)/ sqrt(distance2(X, Y, witgh/2-x, height/2))+
           (q1*ZARIB /distance2(X, Y, witgh/2+x, height/2) ) * (X-x-witgh/2)/ sqrt(distance2(X, Y, witgh/2+x, height/2));

    e[2] = ( Q*ZARIB /distance2(X, Y, xPrime, yPrime) ) * (Y-yPrime)/ sqrt(distance2(X, Y, xPrime, yPrime))+
           (q2 *ZARIB/distance2(X, Y, witgh/2-x, height/2) ) * (Y-height/2)/ sqrt(distance2(X, Y, witgh/2-x, height/2))+
           (q1 *ZARIB/distance2(X, Y, witgh/2+x, height/2) ) * (Y-height/2)/ sqrt(distance2(X, Y, witgh/2+x, height/2));
}

void drawField (int X, int Y,long double maximum)
{


    setcolor(GREEN);
    double en[3],end[3],start[3];
    en[1]= 50/ (maximum) * e[1];
    en[2]= 50/ (maximum) * e[2];
    end[1]= X+ en[1]/ 2; end[2]= Y+ en[2]/ 2;
    start[1] =  X - en[1]/ 2 ; start[2]= Y- en[2]/ 2;
    line(start[1], start[2], end[1], end[2]);
    setcolor(GREEN);
    circle (end[1], end[2], 2);


}

int main ()
{
    char c;
    cout<< "Type s for static and d for dynamic"<< endl;
    cin>>c;
    if( c== 's' || c=='S')
    {
        double X, Y, x=200, xPrime=400, yPrime=450, q1 = 4, q2=4, Q=4;

        //inputs
        cout << "Please enter x , dictance between two q in the center EX: 200"<< endl;
        cin >> x;
        cout << "Please enter q1 EX: 4 "<< endl;
        cin >> q1;
        cout << "Please enter q2 EX:4" << endl;
        cin >> q2;
        cout << "Please enter xPrime, the x argument of the place of Q EX: 400"<< endl;
        cin >> xPrime;
        cout << "Please enter yPrime, the y argument of the place of Q EX: 450"<<endl;
        cin >> yPrime;
        cout << "Please enter the Q EX: 4"<< endl;
        cin >> Q;
        initwindow(witgh, height);
        cleardevice();
        setbkcolor(15);
        setcolor(RED); //drawing bar q2
        circle(witgh/2-x,height/2,5);
        floodfill(witgh/2-x,height/2,RED);
        setcolor(7);
        circle(witgh/2+x,height/2,5); //drawing bar q1
        floodfill(witgh/2+x,height/2,7);
        setcolor(BLUE);
        circle(xPrime,yPrime,5);
        floodfill(xPrime, yPrime,BLUE);
        for (int i=0; i<= witgh/25 -2; i++)//finding the maximum
        {
            for (int j=0; j<= height/25-1; j++)
                {
                 X= 12 + i*25;
                 Y= 12 + j*25;
                 superPos(x, xPrime, yPrime, q1, q2, Q, X, Y);
                 if((sqrt(e[1]*e[1]+e[2]*e[2])) > maximum)
                 {
                     maximum =sqrt(e[1]*e[1]+e[2]*e[2]);
                 }
                }
        }

        for (int i=0; i<= witgh/25 -2; i++)
        {
            for (int j=0; j<= height/25-1; j++)
            {
             X= 12 + i*25;
             Y= 12 + j*25;
             setcolor(15);
             superPos(x, xPrime, yPrime, q1, q2, Q, X, Y);
             drawField(X, Y, maximum);
            }
        }
        getch();
    }

    else
    {
     double X, Y, x=125, xPrime=10, yPrime=40, q1 =-3, q2=3, Q=-3, xAccuracy=4, yAccuracy=4;
     // inputs
        cout << "Please enter x in PIXELS, dictance between two q in the center EX:200 "<< endl;
        cin >> x;
        cout << "Please enter q1 EX:4"<< endl;
        cin >> q1;
        cout << "Please enter q2 EX:4" << endl;
        cin >> q2;
        cout << "Please enter xPrime, the x argument of the first place of Q"<< endl;
        cin >> xPrime;
        cout << "Please enter yPrime, the y argument of the first place of Q"<<endl;
        cin >> yPrime;
        cout << "Please enter the Q EX:4"<< endl;
        cin >> Q;
        accuracy1:
        cout << "Please enter the accuracy of X axis from 1 to 4. Note that larger accuracy may result in slower process!"<<endl;
        cin >> xAccuracy;
        if (xAccuracy<1 || xAccuracy>4)
        goto accuracy1;
        accuracy2:
        cout << "Please enter the accuracy of Y axis from 1 to 4. Note that larger accuracy may result in slower process!"<<endl;
        cin >> yAccuracy;
        if (yAccuracy<1 || yAccuracy>4)
        goto accuracy2;


        initwindow(witgh, height);
        int counter;
        string sentence;
        sentence= "this is"+10;


        if(xPrime >witgh-10 || yPrime >height-10 || xPrime <0 || yPrime <0) // for determining that the pointer is in the screen
        return 0;

        for (int i=0; i<= witgh/25 -2; i=i+5-xAccuracy)
        {
            for (int j=0; j<= height/25 -1; j=j+5-yAccuracy)
                {
                 X= 12 + i*25;
                 Y= 12 + j*25;
                 setcolor(WHITE);
                 superPos(x, xPrime, yPrime, q1, q2, Q, X, Y);
                 if((sqrt(e[1]*e[1]+e[2]*e[2])) > maximum)
                 {
                     maximum =sqrt(e[1]*e[1]+e[2]*e[2]);
                 }
                }
        }
        a:
        setvisualpage(counter%5+2);
        setvisualpage(counter%5+2 );
        counter++;
        setcolor(10);
        //rectangle(600, 0, getmaxx(), 25);
        //floodfill((600+getmaxx())/2 , 12, 10);
        //printf("%s%d","this ", 400);
        setcolor(RED); //drawing bars
        circle(witgh/2-x,height/2,5);
        floodfill(witgh/2-x,height/2,RED);
        circle(witgh/2+x,height/2,5);
        floodfill(witgh/2+x,height/2,RED);
        setcolor(10);
        circle(xPrime,yPrime,5);
        floodfill(xPrime,yPrime,10);
        for (int i=0; i<= witgh/25 -2; i=i+5-xAccuracy)
        {
            for (int j=0; j<= height/25 -1; j=j+5-yAccuracy)
            {
                //if(j=3 && i>(witgh/25-4) ) //to clear the screen for printing text
                //break;
             X= 12 + i*25;
             Y= 12 + j*25;
             superPos(x, xPrime, yPrime, q1, q2, Q, X, Y);
             setcolor(WHITE);
             drawField(X, Y, maximum);
            }
        }
        //delay(.001);
        setactivepage(counter%5);

        cleardevice();
        xPrime++;
        yPrime= yPrime+1;
        goto a;
        getch();
    }
    return 0;
}

