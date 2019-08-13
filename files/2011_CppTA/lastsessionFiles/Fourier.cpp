/*
Pooria Panahifar
Mechanical Engineering
8542009
Birmingham University
International Branch of AUT
Professor:Dr. Bahram Taheri
EFFECT OF HARMONICS IN FOURIER SERIES
*/
/*
Any periodic function f(x) can be shown in terms of what is
called Fourier series, i.e:
   f(x) = a0/2 + a1*cos(x) + a2*cos(2x) + ... + an*cos(nx)+ ..
   + b1*sin(x) +b2*sin(2x) + b3*sin(3x) + ... + bn*sin(nx) + ..
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math>
#include "winbgim.h"

double Pi = 3.14159265358979323846;


int main()
{
	/* request autodetection *//////////////////////////////////////////////////
   int gdriver = DETECT, gmode, errorcode;
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");
   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk) {   /* an error occurred */
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);               /* terminate with an error code */
   }
   /////////////////////////////////////////////////////////////////////////////
   char msg[80];

   setcolor(8);	 sprintf(msg, "4*sin(1*t)/(1*Pi)");		outtextxy(500,40, msg);
   setcolor(RED);	 sprintf(msg, "4*sin(3*t)/(3*Pi)");		outtextxy(500,50, msg);
   setcolor(GREEN);sprintf(msg, "4*sin(5*t)/(5*Pi)");		outtextxy(500,60, msg);
   setcolor(5);	 sprintf(msg, "4*sin(7*t)/(7*Pi)");		outtextxy(500,70, msg);
   setcolor(BLUE); sprintf(msg, "F(X)");						outtextxy(500,30, msg);
   setcolor(WHITE);sprintf(msg, "AIM");						outtextxy(500,20, msg);

   setcolor(YELLOW);
   moveto(500, 20);
   lineto(635, 20);
   lineto(635, 80);
   lineto(500, 80);
   //line(635,80,500,80);  //What is happening?
   lineto(500,20);
   /////////////////////////////////////////////////////////////////////////////
   //Center of Coordinates
	int x0=10;
   int y0=getmaxy()/2;
   setcolor(YELLOW);
   line(x0-10,y0,x0+2*3.14*100,y0);	//X-Axis
   line(x0,y0+200,x0,y0-200);   			//Y-Axis

   getch();

	double t=0.0,y1,y2,y3,y4,y5,y6,fx;

   do
   {
   	y1=4*sin(1*t)/(1*Pi);
      y2=4*sin(3*t)/(3*Pi);
      y3=4*sin(5*t)/(5*Pi);
      y4=4*sin(7*t)/(7*Pi);
      y5=4*sin(9*t)/(9*Pi);
      y6=4*sin(11*t)/(11*Pi);
      fx=y1+y2+y3+y4+y5+y6;

      cout<<t<<"\t"<<y1<<"\t"<<y2<<"\t"<<y3<<"\t"<<y4<<"\t"<<fx<<endl;
      //getch();


   	putpixel(t*100+x0,y0-y1*150,8);
      putpixel(t*100+x0,y0-y2*150,RED);
      putpixel(t*100+x0,y0-y3*150,GREEN);
      putpixel(t*100+x0,y0-y4*150,5);
      putpixel(t*100+x0,y0-fx*150,BLUE);
      putpixel(t*100+x0,y0-y5*150,3);
      putpixel(t*100+x0,y0-y6*150,6);
      if(t<=Pi)
      	putpixel(t*100+x0,y0-(1)*150,15);
      else
      	putpixel(t*100+x0,y0-(-1)*150,15);

      //What are 100 & 150 for?
      delay(10);

   	t = t + 0.005;

   }while(t<=2*Pi);


   getch();
   return 0;
}
   /*       0 BLACK	   8	DARKGRAY
				1 BLUE	   9	LIGHTBLUE
            2 GREEN	   10	LIGHTGREEN
				3 CYAN	   11	LIGHTCYAN
				4 RED	      12	LIGHTRED
				5 MAGENTA   13	LIGHTMAGENTA
				6 BROWN	   14	YELLOW
				7 LIGHTGRAY 15	WHITE 	*/
#include "winbgim.cpp"