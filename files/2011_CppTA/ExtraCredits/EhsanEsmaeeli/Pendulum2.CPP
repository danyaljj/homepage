//in the name of God
/*********************************************
*Written Azar,1390 By: Ehsan Esmaeeli        *
*Pendulum                                    *
*********************************************/
#include <winbgim.h>
//#include <winbgim.cpp>
#include <math.h>
int main ()
{
int gd,gm,x,y=50,x0,r1=10,r2=11,r3=12,r4=13,r5=14,
r6=15,r7=16,r8=17,r9=18,r10=19;
float a1,a2,a3,a4,a5,a6,a7,a8,a9,a10, l=300,
l1=l*pow((16.0/25),2),l2=l*pow((16.0/24),2),l3=l*pow((16.0/23),2),
l4=l*pow((16.0/22),2),l5=l*pow((16.0/21),2),l6=l*pow((16.0/20),2),
l7=l*pow((16.0/19),2),l8=l*pow((16.0/18),2),l9=l*pow((16.0/17),2),l10=l,
g=9.8,y0,a0=M_PI/6,
t1=0,t2=0,t3=0,t4=0,t5=0,t6=0,t7=0,t8=0,t9=0,t10=0;
gd=DETECT;
initgraph(&gd,&gm,"");  //initgraph(graph driver,grapg mode,path to driver)
x=x0=getmaxx()/2;
setlinestyle(0,1,1);  //setlinestyle(line style,pattern,tickness)
settextjustify(1,1) ;
for (y0=1.0;y0<getmaxy();y0=y0+0.5)
{
setcolor(WHITE);
settextstyle(3,0,3); //settextstyle(font mode,direction,font size)
outtextxy(x0,y0,"PENDULUM");
settextstyle(1,0,2);
outtextxy(x0,y0+40,"WRRITEN BY EHSAN ESMAILI");
settextstyle(6,0,1);
outtextxy(x0,y0+80,"PROFESSOR: DR. BAHRAM TAHERI");
outtextxy(x0,y0+110,"Especial thanks to my roommates!!!");
delay(10);
setcolor(BLACK);
settextstyle(3,0,3);
outtextxy(x0,y0,"PENDULUM");
settextstyle(1,0,2);
outtextxy(x0,y0+40,"WRRITEN BY EHSAN ESMAILI");
settextstyle(6,0,1);
outtextxy(x0,y0+80,"PROFESSOR: DR. BAHRAM TAHERI");
outtextxy(x0,y0+110,"Especial thanks to my roommates!!!");
}
for(;;t1+=0.25,t2+=0.25,t3+=0.25,t4+=0.25,t5+=0.25,
t6+=0.25,t7+=0.25,t8+=0.25,t9+=0.25,t10+=0.25)
{
a0=a0-0.0002*a0;
if (a0==0)
break;
a1=a0*sin(sqrt(g/l1)*t1)+M_PI/2;
a2=a0*sin(sqrt(g/l2)*t2)+M_PI/2;
a3=a0*sin(sqrt(g/l3)*t3)+M_PI/2;
a4=a0*sin(sqrt(g/l4)*t4)+M_PI/2;
a5=a0*sin(sqrt(g/l5)*t5)+M_PI/2;
a6=a0*sin(sqrt(g/l6)*t6)+M_PI/2;
a7=a0*sin(sqrt(g/l7)*t7)+M_PI/2;
a8=a0*sin(sqrt(g/l8)*t8)+M_PI/2;
a9=a0*sin(sqrt(g/l9)*t9)+M_PI/2;
a10=a0*sin(sqrt(g/l10)*t10)+M_PI/2;
setcolor(WHITE);
setfillstyle(1,WHITE) ;
line(x,y,x+l1*cos(a1),y+l1*sin(a1));
fillellipse(x+(l1+r1)*cos(a1),y+(l1+r1)*sin(a1),r1,r1);
line(x,y,x+l2*cos(a2),y+l2*sin(a2));
fillellipse(x+(l2+r2)*cos(a2),y+(l2+r2)*sin(a2),r2,r2);
line(x,y,x+l3*cos(a3),y+l3*sin(a3));
fillellipse(x+(l3+r3)*cos(a3),y+(l3+r3)*sin(a3),r3,r3);
line(x,y,x+l4*cos(a4),y+l4*sin(a4));
fillellipse(x+(l4+r4)*cos(a4),y+(l4+r4)*sin(a4),r4,r4);
line(x,y,x+l5*cos(a5),y+l5*sin(a5));
fillellipse(x+(l5+r5)*cos(a5),y+(l5+r5)*sin(a5),r5,r5);
line(x,y,x+l6*cos(a6),y+l6*sin(a6));
fillellipse(x+(l6+r6)*cos(a6),y+(l6+r6)*sin(a6),r6,r6);
line(x,y,x+l7*cos(a7),y+l7*sin(a7));
fillellipse(x+(l7+r7)*cos(a7),y+(l7+r7)*sin(a7),r7,r7);
line(x,y,x+l8*cos(a8),y+l8*sin(a8));
fillellipse(x+(l8+r8)*cos(a8),y+(l8+r8)*sin(a8),r8,r8);
line(x,y,x+l9*cos(a9),y+l9*sin(a9));
fillellipse(x+(l9+r9)*cos(a9),y+(l9+r9)*sin(a9),r9,r9);
line(x,y,x+l10*cos(a10),y+l10*sin(a10));
fillellipse(x+(l10+r10)*cos(a10),y+(l10+r10)*sin(a10),r10,r10);
delay(10);
setcolor(BLACK);
setfillstyle(1,BLACK) ;
line(x,y,x+l1*cos(a1),y+l1*sin(a1));
fillellipse(x+(l1+r1)*cos(a1),y+(l1+r1)*sin(a1),r1,r1);
line(x,y,x+l2*cos(a2),y+l2*sin(a2));
fillellipse(x+(l2+r2)*cos(a2),y+(l2+r2)*sin(a2),r2,r2);
line(x,y,x+l3*cos(a3),y+l3*sin(a3));
fillellipse(x+(l3+r3)*cos(a3),y+(l3+r3)*sin(a3),r3,r3);
line(x,y,x+l4*cos(a4),y+l4*sin(a4));
fillellipse(x+(l4+r4)*cos(a4),y+(l4+r4)*sin(a4),r4,r4);
line(x,y,x+l5*cos(a5),y+l5*sin(a5));
fillellipse(x+(l5+r5)*cos(a5),y+(l5+r5)*sin(a5),r5,r5);
line(x,y,x+l6*cos(a6),y+l6*sin(a6));
fillellipse(x+(l6+r6)*cos(a6),y+(l6+r6)*sin(a6),r6,r6);
line(x,y,x+l7*cos(a7),y+l7*sin(a7));
fillellipse(x+(l7+r7)*cos(a7),y+(l7+r7)*sin(a7),r7,r7);
line(x,y,x+l8*cos(a8),y+l8*sin(a8));
fillellipse(x+(l8+r8)*cos(a8),y+(l8+r8)*sin(a8),r8,r8);
line(x,y,x+l9*cos(a9),y+l9*sin(a9));
fillellipse(x+(l9+r9)*cos(a9),y+(l9+r9)*sin(a9),r9,r9);
line(x,y,x+l10*cos(a10),y+l10*sin(a10));
fillellipse(x+(l10+r10)*cos(a10),y+(l10+r10)*sin(a10),r10,r10);
}
closegraph();
return 0;
}
