#include<stdlib.h>
#include<dos.h>
#include<conio.h>
//#include<graphics.h>
#include "winbgim.h"
#include<stdio.h>
int x0,y0;
void cube(int t,int x,int y);
void main()
{
 int gd=DETECT,gm=VGAHI,g=0;
  initgraph(&gd,&gm," ");
  cleardevice();
  int t=0;
  printf("please enter the speed :");
  scanf("%d",&t);
  int x=0;
  int y=240;
  do
  {
 while(y>0)
 {
   cleardevice();
   x++;
   y=(-1*(4/3))*x+320;
   cube(t,x,y);
   delay(10);
  }
  x=320;
 while(x<640)
 {
   cleardevice();
   x++;
   y=int((3*x)/4)-240;
   cube(t,x,y);
   delay(10);
 }

  while(y<480)
 {
   cleardevice();
   x--;
   y=(int((-1*3*x)/4))+720;
   cube(t,x,y);
   delay(10);
 }

  while(x>0)
 {
   cleardevice();
   x--;
   y=(int((3*x)/4))+240;
   cube(t,x,y);
   delay(10);

  }
  g++;
  } while(g<2);
  getch();
  closegraph();
 }
void cube(int t,int x2,int y2)
{
 if(x0>30)x0=0;
 if(y0>30)y0=0;
 x0++;
 y0++;
 int x[9],y[9];

 x[1]=x2;y[1]=-80+y2;
 x[2]=30+x2;y[2]=-50+y2;
 x[3]=x2;y[3]=-20+y2;
 x[4]=-30+x2;   y[4]=-50+y2;
 x[5]=x2;y[5]=-10+y2;
 x[6]=30+x2;y[6]=20+y2;
 x[7]=x2;y[7]=50+y2;
 x[8]=-30+x2;   y[8]=20+y2;
 cleardevice();
 randomize();
 int col;
 do{
    col=rand()%15;
   }while(col==0);
 setcolor(col);
 x[1]=x[1]+x0;y[1]=y[1]+y0;
 x[2]=x[2]-x0;y[2]=y[2]+y0;
 x[3]=x[3]-x0;y[3]=y[3]-y0;
 x[4]=x[4]+x0;y[4]=y[4]-y0;

 x[5]=x[5]+x0;y[5]=y[5]+y0;
 x[6]=x[6]-x0;y[6]=y[6]+y0;
 x[7]=x[7]-x0;y[7]=y[7]-y0;
 x[8]=x[8]+x0;y[8]=y[8]-y0;

 line(x[1],y[1],x[2],y[2]);
 line(x[2],y[2],x[3],y[3]);
 line(x[3],y[3],x[4],y[4]);
 line(x[4],y[4],x[1],y[1]);
 line(x[5],y[5],x[6],y[6]);
 line(x[6],y[6],x[7],y[7]);
 line(x[7],y[7],x[8],y[8]);
 line(x[8],y[8],x[5],y[5]);

 line(x[1],y[1],x[5],y[5]);
 line(x[2],y[2],x[6],y[6]);
 line(x[3],y[3],x[7],y[7]);
 line(x[4],y[4],x[8],y[8]);

 delay(t);
 }

 #include "winbgim.cpp"
