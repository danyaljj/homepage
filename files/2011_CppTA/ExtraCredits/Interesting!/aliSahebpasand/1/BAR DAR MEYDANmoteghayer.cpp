#include <winbgim.h>
//#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
// Extra Credit: Why the pixel color change happens only for a
//limited number of times? 0.5 out of 20 points in the final.
using namespace std;
int main (void)
{
   /* request autodetection */
   int gdriver = DETECT, gmode, errorcode;
   int  x, y, color=7, maxx, maxy, maxcolor, seed;
   float dj,j;
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
   int poly[6],poly2[6];
   char array[3],array2[3];
   double pi=3.1415,m=0.01,q=1,B=1,a=1000,b=1000,c=300,xc=200,yc=200;
   cout<<"jahate meydan dar rastaye khate sefid va ro be BALAST,noe bar + ast";
   line(xc,getmaxy(),xc,0);
   /*cout<<"enter mass";
   cin>>m;
   cout<<"enter q";
   cin>>q;
   cout<<"enter B";
   cin>>B;
   cout<<"v=ai+bj+ck enter a,b,c ";
   cin>>a;
   cin>>b;
   cin>>c;*/
   int c2=0,c3=2;
   double T=(((2*pi)*m)/(q*B));
   double r=(m*(sqrt(pow(a,2)+pow(b,2))))/(q*B);
   for(double t=T/6;t<=(100*T);t=t+T/200,delay((T/200)*pow(10,3)))
   {
   array[0]='B';
   array[1]=' ';
   poly[0]=xc;
   poly[1]=0;
   poly[2]=xc-10;
   poly[3]=10;
   poly[4]=xc+10;
   poly[5]=10;
   fillpoly(3,poly);
   c2=c2+1;
   outtextxy(xc+20,1,array);
   double tet=((2*pi)*t)/T;
   double z= c*t;
   B=0.03*z;
   T=(((2*pi)*m)/(q*B));
   r=(m*(sqrt(pow(a,2)+pow(b,2))))/(q*B);
   if(c2==1)
   {
   //putpixel((xc-(((r)*sin(tet)))),((yc+((r*cos(tet)))-z)),2);
   line(xc-20,((yc+((r*cos(tet)))-z))+20,(160),(250));
   poly2[0]=160;
   poly2[1]=250;
   poly2[2]=165;
   poly2[3]=250;
   poly2[4]=157;
   poly2[5]=255;
   fillpoly(3,poly2);
   array2[0]='v ';
   //array2[1]=' ';
   outtextxy(130,245,array2);
   }
   if(c2>2)
   putpixel((xc-(((r)*sin(tet)))),((yc+((r*cos(tet)))-z)),2);
   //c=((-10)*t)+c;
   setcolor(6);
   }

   cout<<"period= "<<T<<"s r= "<<r<<"m ";
   getch();
   closegraph();
   return 0;
}

//include "winbgim.cpp"
