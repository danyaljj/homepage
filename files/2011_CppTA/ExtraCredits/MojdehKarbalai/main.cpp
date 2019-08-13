#include <winbgim.h>
//#include <conio.h>
#include<cmath>
#include<iostream>
#include<graphics.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
int nkbhit;
using namespace std;
 main()
{
    nkbhit=0;
    double p;//teded avang
    int n;
    double x0[30],y0[30],l[30];
    long double damane;
    cout<<"enter how many pendulums do you want?\n";
    cin>>p;
    cout<<"enter Amplitude"<<"\n";
    cin>>damane;

    cout<<"enter delay time(ms)"<<"\n";
    cin>>n;
    double lenght=247;
    double x1[15],y1[15],x2[15],y2[15];
   // int gd=DETECT,gm=0,errorcode;
   // initgraph(&gd,&gm,"");
     int gdriver = DETECT, gmode, errorcode;
   char msg[80];       // a char vector of length 80
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)                                         /*grOk=0*/
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));   /*grapherrormsg(0):The opreation completed successfully.*/
      printf("Press any key to halt:");                           /*%s:string */
      getch();                                                    /*%f:float  */
      exit(1);                                                    /*%d:integer*/
   }
    line(320,50,320,297);
    circle(320,297,10);
    for(int a=0;a<p;a++){
        setcolor(9);
        x0[a]=320;
        y0[a]=297;
      //  x0[a]=320-8.5*a;
      //  y0[a]=297-5*a;
        line(320,20,320-8.5*a,297-5*a);
        circle(320-8.5*a,297-5*a,10);

       }
       delay(100);
     //  for(int g=14;g>=0;g++)
       //l[g]=pow(16/(16+g),2)*24.7;
    /*   l[0]=24.7*5;
       l[1]=22.7*5;
       l[2]=21.0*5;
       l[3]=19.5*5;
       l[4]=18.1*5;
       l[5]=16.9*5;
       l[6]=15.8*5;
       l[7]=14.8*5;
       l[8]=13.9*5;
       l[9]=13.1*5;
       l[10]=12.3*5;
       l[11]=11.6*5;
       l[12]=11.0*5;
       l[13]=10.4*5;
       l[14]=9.85*5;*/




        for(int g=0;g<p;g++)
          l[g]=180*16*16/((16+g)*(16+g));

       int t=1;

   long double i=0;

       cleardevice();
       int page=0;
      //  for(double i=1;i<1000000000000000;i+=0.05){
        while(damane>0){

              // break;
             setcolor(9);
            settextstyle(1,0,6);
            outtextxy(10,5,"Pendulums Waves");
                    setactivepage(page);
            page++;
          page%=2;
          setvisualpage(page);
            cleardevice();
          //  setactivepage(page);
          //  page++;
          //  page%=2;
          //  setvisualpage(page);
          //  cleardevice();
            for(int j=0;j<p;j++){
                setcolor(15-j);
               // setfillstyle(1,j);
                long double x[30],y[30];
                x[j]=(damane)*sin(sqrt(9.8/l[j])*i)+x0[j];
                y[j]=sqrt((pow(l[j],2)-pow(x[j]-x0[j],2)))+y0[j];
                line(320,0,x[j],y[j]);
                circle(x[j],y[j],10);

            }
            damane-=0.005;


            delay(n);

           /*setactivepage(page);
            page++;
          page%=2;
          setvisualpage(page);
            cleardevice();
*/
           // t++;
            //cleardevice();
            //setactivepage(t+1);
            //setvisualpage(1);
            //cleardevice();

           // if(kbhit())
           //     nkbhit++;
           // if(nkbhit>2)
           //     break;
        if(damane<=0){
                   cleardevice();
        setcolor(15);
        settextstyle(1,0,4);
        outtextxy(20,200,"Thanks From Dr. Taheri");
        outtextxy(20,300,"Mojdeh Karbalaee Motalleb");
        delay(5000);

                  break;
        }
            i+=0.05;
            t++;
        }
            setactivepage(page);
            page++;
            page%=2;
            setvisualpage(page);
            cleardevice();

        circle(100,100,50);
           cleardevice();
        setcolor(15);
        settextstyle(1,0,4);
        outtextxy(20,200,"Thanks From Dr. Taheri");
        outtextxy(20,300,"Mojdeh Karbalaee Motalleb");
        delay(5000);
//cleardevice();



//  printf("%s"msg);
//cout<<msg;


    closegraph();
}
