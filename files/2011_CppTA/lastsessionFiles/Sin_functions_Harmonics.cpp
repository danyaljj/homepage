/*
Pooria Panahifar
Mechanical Engineering
8542009
International Branch of AUT
Instructor:Dr.Taheri
HARMONICS
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math>
#include "winbgim.h"

double Pi = 3.14159265358979323846;
char msg[80];

int main()
{
	/* request autodetection */
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

   //Center of Coordinates
	int x0=10;
   int y0=getmaxy()/2;
   setcolor(YELLOW);
   line(x0-10,y0,x0+2*3.14*100,y0);	//X-Axis
   line(x0,y0+20,x0,y0-200);   			//Y-Axis

   getch();

	double t=0.0,x[5];

   do
   {
   	x[1]=sin(t);
      x[2]=sin(2*t);
      x[3]=sin(3*t);
      x[4]=sin(4*t);

      cout<<t<<"\t"<<x[1]<<"\t"<<x[2]<<"\t"<<x[3]<<"\t"<<x[4]<<endl;
      //getch();


   	putpixel(t*100+x0,y0-x[1]*200,BLUE);
      putpixel(t*100+x0,y0-x[2]*200,RED);
      putpixel(t*100+x0,y0-x[3]*200,GREEN);
      putpixel(t*100+x0,(y0-x[4]*200),7);
      delay(20);

   	t = t + 0.005;
   }while(t<=2*Pi);

   getch();
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
