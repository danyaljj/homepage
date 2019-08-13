#include<iostream>
#include"graphics.h"
#include"winbgim.h"
using namespace std;

void jadval(void);
void decode(int& x , int& y);
void rasm(int a[5][5]);
void ramz(int a[5][5]);
void entekhab(int a[5][5], int& x, int& y);

int s=1;

int main()
{
	int x,y,a[5][5]={0}; 
    initwindow(350,350);
	jadval();
	momtaz:
	do
	{
         getmouseclick(WM_LBUTTONDOWN, x, y);
	}while(x==-1 && y==-1);
	decode(x,y);
	if(a[x][y]!=0)
        goto momtaz;
	a[x][y]=2;
	rasm(a);
	ramz(a);
	if(a[0][0]==3 || a[0][1]==3 || a[0][2]==3 || a[0][3]==3 || a[0][4]==3 || a[1][4]==3 || a[2][4]==3 || a[3][4]==3)
	{
		outtextxy (115, 150,"You are winner!!!!!"); 
		cin>>x;
		return 0;
	}
	entekhab(a,x,y);
	a[x][y]=1;
		if(s==10)
	{
	    outtextxy (100, 150,"there`s no winner!!!!!"); 
		cin>>x;
		return 0;
	}
	rasm(a);
	ramz(a);
	if(a[1][0]==3 || a[2][0]==3 || a[3][0]==3 || a[4][0]==3 || a[4][1]==3 || a[4][2]==3 || a[4][3]==3 || a[4][4]==3)
	{
		outtextxy (115, 150,"I am winner!!!!!"); 
		cin>>x;
		return 0;
	}
	goto momtaz;
	return 0;
}



void jadval(void)
{
	line(25,25,325,25);
	line(25,25,25,325);
	line(325,25,325,325);
	line(25,325,325,325);
	line(125,25,125,325);
	line(225,25,225,325);
	line(25,125,325,125);
	line(25,225,325,225);
}

void decode(int& x , int& y)
{
	if(x>25 && x<125)
	{
		if(y>25 && y<125)
			{x=1;y=1;}
		if(y>125 && y<225)
			{x=1;y=2;}
		if(y>225 && y<325)
			{x=1;y=3;}
	}

	if(x>125 && x<225)
	{
		if(y>25 && y<125)
			{x=2;y=1;}
		if(y>125 && y<225)
			{x=2;y=2;}
		if(y>225 && y<325)
			{x=2;y=3;}
	}

	if(x>225 && x<325)
	{
		if(y>25 && y<125)
			{x=3;y=1;}
		if(y>125 && y<225)
			{x=3;y=2;}
		if(y>225 && y<325)
			{x=3;y=3;}
	}
}

void rasm(int a[5][5])
{
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		{
			if(a[i][j]==2)
				{setcolor(5);setfillstyle(SOLID_FILL,5);}
			if(a[i][j]==1)
				{setcolor(2);setfillstyle(SOLID_FILL,2);}
			if(a[i][j]!=0)
				fillellipse(100*(i-1)+75,100*(j-1)+75,40,40);
		}
		s++;
}

void ramz(int a[5][5])
{
	int b[3][3]={0},c[3][3]={0};

	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++)
			if (a[i+1][j+1]==2)
				b[i][j]=1;

	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++)
			if (a[i+1][j+1]==1)
				c[i][j]=1;

	a[0][0]=b[0][0]+b[1][1]+b[2][2];
	a[0][1]=b[0][0]+b[1][0]+b[2][0];
	a[0][2]=b[0][1]+b[1][1]+b[2][1];
	a[0][3]=b[0][2]+b[1][2]+b[2][2];
	a[0][4]=b[0][2]+b[1][1]+b[2][0];
	a[1][4]=b[0][2]+b[0][1]+b[0][0];
	a[2][4]=b[1][2]+b[1][1]+b[1][0];
	a[3][4]=b[2][2]+b[2][1]+b[2][0];

	a[1][0]=c[0][0]+c[0][1]+c[0][2];
	a[2][0]=c[1][0]+c[1][1]+c[1][2];
	a[3][0]=c[2][0]+c[2][1]+c[2][2];
	a[4][0]=c[2][0]+c[1][1]+c[0][2];
	a[4][1]=c[2][0]+c[1][0]+c[0][0];
	a[4][2]=c[2][1]+c[1][1]+c[0][1];
	a[4][3]=c[2][2]+c[1][2]+c[0][2];
	a[4][4]=c[2][2]+c[1][1]+c[0][0];
}

void entekhab(int a[5][5],int& x, int& y)
{
    for(int j=1;j<=3;j++)
		if(a[4][j]==2)
		{
			for(int i=1;i<=3;i++)
				if (a[i][j]==0)
				{x=i;y=j;return;}
		}
				

	for(int i=1;i<=3;i++)
		if(a[i][0]==2)
		{
			for(int j=1;j<=3;j++)
				if (a[i][j]==0)
				{x=i;y=j;return;}
		}

	if (a[4][4]==2)
	{
		if (a[1][1]==0)
			{x=1;y=1;return;}
		if (a[2][2]==0)
			{x=2;y=2;return;}
		if (a[3][3]==0)
			{x=3;y=3;return;}
	}

	if (a[4][0]==2)
	{
		if (a[1][3]==0)
			{x=1;y=3;return;}
		if (a[2][2]==0)
			{x=2;y=2;return;}
		if (a[3][1]==0)
			{x=3;y=1;return;}
	}
	
	for(int j=1;j<=3;j++)
		if(a[0][j]==2)
		{
			for(int i=1;i<=3;i++)
				if (a[i][j]==0)
				{x=i;y=j;return;}
		}
				

	for(int i=1;i<=3;i++)
		if(a[i][4]==2)
		{
			for(int j=1;j<=3;j++)
				if (a[i][j]==0)
				{x=i;y=j;return;}
		}

	if (a[0][0]==2)
	{
		if (a[1][1]==0)
			{x=1;y=1;return;}
		if (a[2][2]==0)
			{x=2;y=2;return;}
		if (a[3][3]==0)
			{x=3;y=3;return;}
	}

	if (a[0][4]==2)
	{
		if (a[1][3]==0)
			{x=1;y=3;return;}
		if (a[2][2]==0)
			{x=2;y=2;return;}
		if (a[3][1]==0)
			{x=3;y=1;return;}
	}

	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			if(a[i][j]==0)
				{x=i;y=j;}

}




             
             
             
             
