#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <winbgim.h>
#include <math.h>
#include <iomanip>

using namespace std;
long double e[3];
long double maximum;

// a function for measuring the distance between two points
long int distance2 (int x1, int y1, int x2, int y2 )
{
    return pow(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)),0.50);
}

long double superPos (int x,  int q1, int q2,  int X, int Y)
{
    if( (sqrt(distance2(X, Y, 400-x, 300))==0 ) || (sqrt(distance2(X, Y, 400+x, 300))==0) ) ///// determine not to divide by zero
    {
        return 0;
    }

    e[1] =
           (q2* 100000000/distance2(X, Y, 400-x, 300) ) * (X+x-400)/ sqrt(distance2(X, Y, 400-x, 300))+
           (q1* 100000000/distance2(X, Y, 400+x, 300) ) * (X-x-400)/ sqrt(distance2(X, Y, 400+x, 300));

    e[2] =
           (q2* 100000000/distance2(X, Y, 400-x, 300) ) * (Y-300)/ sqrt(distance2(X, Y, 400-x, 300))+
           (q1* 100000000/distance2(X, Y, 400+x, 300) ) * (Y-300)/ sqrt(distance2(X, Y, 400+x, 300));
}

void drawField (int X, int Y,long double maximum)
{

    double en[3],end[3],start[3];

    setcolor(GREEN);

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



        double X, Y, x=100, xPrime=300, yPrime=400, q1 =-3, q2=2, xAccuracy=4, yAccuracy=4;

        //// asking
        cout << "Please enter x , dictance between two q in the center EX: 100 "<< endl;
        cin >> x;
        cout << "Please enter q1 EX : -3"<< endl;
        cin >> q1;
        cout << "Please enter q2 EX : 2" << endl;
        cin >> q2;
        cout << "Please enter xPrime, the x argument of the first place of Q EX:300"<< endl;
        cin >> xPrime;
        cout << "Please enter yPrime, the y argument of the first place of Q EX:400"<<endl;
        cin >> yPrime;

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


        initwindow(800, 600);
        int counter;
        //a:


        if(xPrime >800 || yPrime >550 || xPrime <0 || yPrime <0) // for determining that the pointer is in the screen
        return 0;

        for (int i=0; i<= 30; i=i+5-xAccuracy)
        {
            for (int j=0; j<= 22; j=j+5-yAccuracy)
                {
                 X= 12 + i*25;
                 Y= 12 + j*25;
                 setcolor(WHITE);
                 superPos(x, q1, q2, X, Y);
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
        setcolor(RED); //drawing bars
        circle(400-x,300,5);
        floodfill(400-x,300,RED);
        circle(400+x,300,5);
        floodfill(400+x,300,RED);
        setcolor(15);
        circle(xPrime,yPrime,5);
        floodfill(xPrime,yPrime,15);
        for (int i=0; i<= 30; i=i+5-xAccuracy)
        {
            for (int j=0; j<= 22; j=j+5-yAccuracy)
            {
             X= 12 + i*25;
             Y= 12 + j*25;
             superPos(x, q1, q2, X, Y);
             setcolor(WHITE);
             drawField(X, Y, maximum);
            }
        }
        superPos(x, q1, q2, xPrime, yPrime);
        xPrime+= e[1]/maximum*4;
        yPrime+= e[2]/maximum*4;

        cout<<"xPrime is: "<<setw(10)<< xPrime<<"   "<<"yPrime is: "<<yPrime<<endl;
        //cout<<"en[1] is "<<setw(10)<<en[1]<<"   "<<"en[2] is "<<en[2]<<endl<<endl;


        //to change the pages
        setactivepage(counter%5);
        cleardevice();
        //getch();
        goto a;


}

