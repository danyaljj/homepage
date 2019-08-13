/* CREATED BY : MOHAMMAH. H CHAGHAZARDI WINTER 2011- spring 2012
        A PROGRAM FOR CALCULATING AND DRAWING THE DEFLECTION OF A BEAM*/


#include <iostream>
#include <conio.h>
#include <vector>
#include<cmath>
#include<iomanip>
#include<graphics.h>
#include<winbgim.h>
#include <stdio.h>


using namespace std;
const double PI=3.1415;
const double E= 26000;
const double I= 32.25;
const double P= 10;
const double L= 50;

int N =1; // the number of unknowns the number of segments will be N+1  or the number of y(s)
int counter=N;
int theHighest;
//bool flag=true; //for checking the condition of countinuing the progess and increasing N


//functions
double calculatingMi(int i);
int thomas(double r[], double  x[]); // for calculating the mateix using thomas algorithm
void numberingRightHandSide(double rightHandSide[]);// for nubering right handside matrix
int printingResult(double result[]);// for printing the result
double calcultingError(double result[]);
double graphics(double result[]);
double PxFurmula(double X);
double tetaFurmula(double X);
double momentFurmula(double X);
double extraGraphics();


int main(void)
{
    cout<<"please enter the number of segments\n";
    cin >> N;
    double deltaY[N+1];// unknowns array
    double rightHandSide[N+1];  // right handside array
    numberingRightHandSide(rightHandSide);
    thomas(rightHandSide, deltaY);
    //calcultingError(deltaY);
    graphics(deltaY);
    extraGraphics();

    getch();
}
double extraGraphics()
{
    /// for drawing px, the const amount
    for (int i=0; i<=N; i++)
    {
        line(getmaxx()/2-300+600/N*i, getmaxy()/2-200-30, getmaxx()/2-300+600/N*i, getmaxy()/2-200-30+20*PxFurmula(600/N*i)/ P);
        circle (getmaxx()/2-300+600/N*i, getmaxy()/2-200-30+20*PxFurmula(600/N*i)/ P, 2);
    }
    /// for drawing a graph
    setlinestyle(0, 0, 1);
    line(getmaxx()/2-300, getmaxy()-10, getmaxx()/2-300,getmaxy()-410);
    line(getmaxx()/2-300, getmaxy()-10, getmaxx()/2+300,getmaxy()-10) ;
    /// for drawing teta
    moveto(getmaxx()/2-300, getmaxy()-10);
    setcolor(2);
    for(int i=0; i<=N; i++)
    {
        lineto(getmaxx()/2-300+600.0*i/N, 1000*(tetaFurmula(L*i/N))+getmaxy()-100);
        circle(getmaxx()/2-300+600.0*i/N, 1000*(tetaFurmula((L*i/N)))+getmaxy()-100, 2);
        floodfill(getmaxx()/2-300+600.0*i/N, 1000*(tetaFurmula((L*i/N)))+getmaxy()-100, 2);
        //cout<<"teta(x)= "<<tetaFurmula((L*i/N))<<"\n";  // to check the functioning of tetafurmula
        //getch();
    }
    moveto(getmaxx()/2-300, getmaxy()/2-35);
    setlinestyle(0, 0, 2);
    for(int i=0; i<=N; i=i++)
    {
        line(getmaxx()/2-300+600/N*i+10, getmaxy()/2-200, getmaxx()/2-300+600/N*i+10, getmaxy()/2-200-30*momentFurmula(L/N*i)/ momentFurmula(0));
        circle (getmaxx()/2-300+600/N*i+10, getmaxy()/2-200-30*momentFurmula(L/N*i)/ momentFurmula(0), 2);
    }
}
double momentFurmula(double X)
{
    return(P/E/I*X-P/E/I/2*L);
}
double tetaFurmula(double X)
{
    return(P*pow(X, 3)/(E*I*6) - P*L*pow(X, 2)/(E* I*4)+ P*pow(L, 3)/(E* I*24));
}
double PxFurmula(double X)
{
    return P;
}
double graphics(double result[])
{
    initwindow(800, 600);
    //line(getmaxx()/2-300, getmaxy()/2-200, getmaxx()/2+ 300, getmaxy()/2-200);
    moveto(getmaxx()/2-300, getmaxy()/2-200);
    for(int i=1; i<=N; i++)
    {
        lineto(getmaxx()/2-300 + 600.0*i/(N+1), getmaxy()/2-200+100*(-1)*result[i]);          /// DRAWING LINES
        circle(getmaxx()/2-300 + 600.0*i/(N+1), getmaxy()/2-200+100*(-1)*result[i], 2);       /// DRAWING THE CIRCLES
        floodfill(getmaxx()/2-300 + 600.0*i/(N+1), getmaxy()/2-200+100*(-1)*result[i], WHITE);/// FILLING
    }
    lineto(getmaxx()/2+ 300, getmaxy()/2-200);                                                /// LINKING THE LAST POINT TO THE END
    settextstyle(9, HORIZ_DIR,300 );
    outtextxy(10, 10, "Created by Mohammad Hossein Chaghazardi spring 2012");
    // the next line is for showing the constamts in botoom of the viewport
    outtextxy(50, 510, "E= 26000 MN/m^2");outtextxy(50, 530, "L= 50 m");outtextxy(50, 550, "I= 32.25 m^4");outtextxy(50, 570, "P= 10 MN/m");
    // the next lines are for drawing the beam
    setlinestyle(0, 0, 5);
    line(getmaxx()/2-300, getmaxy()/2-200, getmaxx()/2+300, getmaxy()/2-200);
    /// the following lines are for drawing  supports at the ends
    setlinestyle(0, 0, 1);
    line(getmaxx()/2-300, getmaxy()/2-200, getmaxx()/2-300-25*sin(PI/6), getmaxy()/2-200+25*cos(PI/6)) ;
    line(getmaxx()/2-300, getmaxy()/2-200, getmaxx()/2-300+25*sin(PI/6), getmaxy()/2-200+25*cos(PI/6)) ;
    line(getmaxx()/2-300+25*sin(PI/6), getmaxy()/2-200+25*cos(PI/6) , getmaxx()/2-300-25*sin(PI/6), getmaxy()/2-200+25*cos(PI/6)) ;
    floodfill((getmaxx()/2-300), (getmaxy()/2-200)+25*cos(PI/6)/2, WHITE);
    line(getmaxx()/2+300, getmaxy()/2-200, getmaxx()/2+300-25*sin(PI/6), getmaxy()/2-200+25*cos(PI/6)) ;
    line(getmaxx()/2+300, getmaxy()/2-200, getmaxx()/2+300+25*sin(PI/6), getmaxy()/2-200+25*cos(PI/6)) ;
    line(getmaxx()/2+300+25*sin(PI/6), getmaxy()/2-200+25*cos(PI/6) , getmaxx()/2+300-25*sin(PI/6), getmaxy()/2-200+25*cos(PI/6)) ;
    floodfill((getmaxx()/2+300), (getmaxy()/2-200)+25*cos(PI/6)/2, WHITE);
}
double calcultingError(double result[])
{
       //finding the maxmimum of deltay ;
       double maximum;
       for(int i=1; i<=N; i++)
        {
            if (result[i]<maximum)
                {
                    maximum= result[i];
                    theHighest=i;
                }
        }

        double error;
        cout<<"the maximum deflection of the Beam with "<<N+1<<"segments is= "<<setprecision(2)<<maximum<<" m"<<endl;
        error= fabs((1-fabs(maximum/(P*pow(L, 4)/E/I*5/384))));
        return error;
        //flag=false;
        //cout<<"at N="<<N<<" the error is  "<<setprecision(2)<<error*100<<" % and the result is :"<<endl;
        //printingResult(result);
}


int printingResult(double result[])
{
    for(int i=1; i<=N; i++)
        cout<<"deltaY["<<i<<"]= "<<result[i]<<" meters"<<endl;
        cout<< "and the maxinum deflection is : "<<result[theHighest]<<" meters"<<endl;

}



double calculatingMi(int i)
{
    double x;
    x= L*i/(N+1);
    return ((P*L/2)*x- P/2*x*x);
}


void numberingRightHandSide(double rightHandSide[])                   // for numbering the right handside matrix
{
    double deltaX2=(L/(N+1))*(L/(N+1));
    for(int i=1; i<=N; i++)
        rightHandSide[i]= deltaX2/E / I* calculatingMi(i) ;

}


int thomas(double r[], double  x[])   // a function for solving the matrix
{
   double e[N+1], f[N+1], g[N+1];

   for(int i=1; i<=N; i++)
   {
      e[i]=1;
      f[i]=-2;                   //for making the array for solving the 2nd defussion
      g[i]=1;
   }

   for(int j=2; j<=N; j++)
   {
      e[j]=e[j]/f[j-1];
      f[j]=f[j]-e[j]*g[j-1];
      r[j]=r[j]-e[j]*r[j-1];

   }
   x[N]=r[N]/f[N];                                  // numering the X (answer array)
   for (int m=N-1; m>=1; m--)
   {
      x[m]=(r[m]-g[m]*x[m+1])/f[m];
   }
}
