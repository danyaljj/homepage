#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <winbgim.h>
#include <math.h>

using namespace std;
double teta0=.25;
int counter=1;


void drawPan(int n, int l, double t , int r, int color, double eta, double seta )
{

    //setactivepage(counter%2 +1);

    double teta;
    setcolor( color );
    teta= -teta0 *cos ((sqrt(1000/l)*t)) ;
    line(650-50*n*sin(eta), 0+ 50*n*sin(seta), 650 + l*10*sin(teta)-50*n*sin(eta), l*10*cos(teta)+ 50*n*sin(seta));
    circle(650 + l*10*sin(teta)-50*n*sin(eta), l*10*cos(teta)+ 50*n*sin(seta), r);
    //setvisualpage (counter*2 +1);
    delay(.25);
}
/*void clearPan(int l, int t, int r,int color )
{
    double teta;
    teta= -teta0 *cos ((sqrt(1000/l)*t)) ;
    setcolor(BLACK);
    delay(.25);
    line(650, 0, 650 + l*sin(teta), l*cos(teta));
    circle(650 + l*sin(teta), l*cos(teta), r);
}*/

int main()
{

    double t=0;
    double n,alpha,teta;
    cout<<"please enter teta, the degree of x viewport in radians EX : 0.01"<<endl;
    cin >> teta;
    cout<<"please enter alpha, the degree of z viewport in radians EX : 0.1"<<endl;
    cin >> alpha;
    initwindow(1300,768);
    while (1)
    {
    setvisualpage(counter%5+2);
    setvisualpage(counter%5+2 );

    counter++;
    /*for ( double i=1; i<=n; i++)
    {
      drawPan(600/i , t, 20-i,i);
    }*/


    drawPan(10, 60, t, 20, 15,alpha,teta);
    drawPan( 9, 58, t, 19, 14,alpha,teta);
    drawPan( 8, 54, t, 18, 13,alpha,teta);
    drawPan( 7, 51, t, 17, 12,alpha,teta);
    drawPan( 6, 47, t, 16, 10,alpha,teta);
    drawPan( 5, 42, t, 15,  9,alpha,teta);
    drawPan( 4, 36, t, 14,  8,alpha,teta);
    drawPan( 3, 28, t, 14,  7,alpha,teta);
    drawPan( 2, 20, t, 14,  6,alpha,teta);
    drawPan( 1, 15, t, 14,  5,alpha,teta);
    line(650-50*1*sin(alpha), 50*1*sin(teta), 650-50*10*sin(alpha), 50*10*sin(teta));

    //getch();
    setactivepage(counter%5);
    cleardevice();
    t=t+.005;

    }


}

