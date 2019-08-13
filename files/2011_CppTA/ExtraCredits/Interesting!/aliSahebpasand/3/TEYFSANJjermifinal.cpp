#include <winbgim.h>
//#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
// Extra Credit: Why the pixel color change happens only for a
//limited number of times? 0.5 out of 20 points in the final.
int main (void)
{
   /* request autodetection */
   int gdriver = DETECT, gmode, errorcode;
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)
   {  /* an error occurred */
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);               /* terminate with an error code */
   }
   setcolor(4);
   int xB=20,yB=1;
   while(yB<440)
   {
   yB=yB+30;
   xB=20;
   while(xB<getmaxx())
   {
   fillellipse(xB,yB,4,4);
   xB=xB+30;
   }
   }
   double pi=3.1415,B=1,x=400,q=1,m=1,v=1000,xs=35,ys=getmaxy();
   double t=0,yend;
   /*cout<<"enter x start"<<endl;
   cin>>xs;*/
   cout<<"x start ="<<xs<<endl;
   //cout<<"enter distant from strat(m)"<<endl;
   //cin>>x;
   cout<<"distant from start ="<<x<<" m"<<endl;
   //cout<<"enter B(T)"<<endl;
   //cin>>B;
   cout<<"B ="<<B<<" T"<<endl;
   //cout<<"enter q(C)"<<endl;
   //cin>>q;
   cout<<"q = "<<q<<" C"<<endl;
   //cout<<"enter voltage"<<endl;
   //cin>>v;
   cout<<"voltage = " <<v<<" v"<<endl<<endl;
   m=(pow(B,2)*q*pow(x,2))/(8*v);
   cout<<"m = "<<m<<" kg";
   while((ys-(sqrt((2*q*v)/m)*t))> 450)
   {
   delay(30);
   t=t+0.03;
   yend=ys-(sqrt((2*q*v)/m))*t;
   putpixel(xs,yend,3);
   }
   double T=(2*pi*(x/2))/(sqrt((2*q*v)/m));
   double tet=0;
   for(double t=0;t<=10*T&&(tet-pi<0.01);t=t+T/3000,delay((t/3)))
   {
   tet=((2*pi)*t)/T;
   if(tet-pi<0.01)
   {
   putpixel(xs+((x/2)-(((x/2)*cos(tet)))),((450-(((x/2)*sin(tet))))),6);
   }
   }
   getch();
   closegraph();
   return 0;
}

//#include "winbgim.cpp"
