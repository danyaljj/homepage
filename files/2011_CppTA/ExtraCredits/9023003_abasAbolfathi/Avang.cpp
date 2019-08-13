#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int i,m,n,mp,np,size,num;                                                   //i:counter  m&n&mp&np:int shodeye x&y  size:size avang  num:teadade avang ha
	double x,y,t=0,time,deathtime,teta,li,lf,l,deltal;                          //x&y:mokhtasate avang  t&time&deathtime: zaman ha  teta:zaviye enheraf  li&lf&l&deltal:tule avang ha

   	cout<<"enter the number of pandul=";                                        //maghadire avaliye ra az karbar migirad
	cin>>num;
   	cout<<"enter time=";
	cin>>time;
	cout<<"enter death time=";
	cin>>deathtime;
	cout<<"enter teta=";
	cin>>teta;
	cout<<"enter Li=";
	cin>>li;
	cout<<"enter lf=";
	cin>>lf;
	cout<<"time="<<time<<"  death time="<<deathtime<<"  teta="<<teta<<"  Li="<<li<<"  Lf="<<lf<<endl<<"the number of pandul="<<num;

    teta=teta/180*3.141592;                                                     //teta ra az daraje be radian barmigardanad.
	if (li<lf){l=li; li=lf; lf=l;}                                              //tartibe tule ebtedaee va entehaee ra check mikonad

	initwindow(800,600);                                                        //panjareye namayesh ra dar abade 800*600 baz mikonad

    double w[num];                                                              //in ghesmat w ra baraye avanghaye ebtadaee va entehaee hesab mikonad
    w[0]= sqrt(9.8/li)/(1+1/16*teta*teta+11/3072*pow(teta,4.0)+173/737280*pow(teta,6.0));
    w[num-1]= sqrt(9.8/lf)/(1+1/16*teta*teta+11/3072*pow(teta,4.0)+173/737280*pow(teta,6.0));

    for(i=1;i<num-1;i++)
        w[i]=w[0]-(w[0]-w[num-1])/(num-1)*i;                                    //ba tavajo be w haye avang haye ebtedaee va entehaee w avang ha ra besurate khati hesab mikonad

    deltal=(li-lf)/(num-1);                                                     //az inja lf hokme delta l ra peyda mikonad ta tule avangha besurate khati takheer konad

    x=li*sin(teta);                                                             //kole 11 khate badi vazifeye tarsime khtkeshe ebtedaee ra darad
    m=400-250*x/li;
	n=(250*x/li+20/cos(teta))/tan(teta);
    mp=400-450*x/li;
	np=(450*x/li+20/cos(teta))/tan(teta);
	line(m,n,mp,np);
	line(m,n,m+27,n);
	line(m+27,n,mp+27,np);
	line(mp,np,mp+27,np);
	setfillstyle(CLOSE_DOT_FILL,WHITE);
	floodfill(m+13,n+10,WHITE);

	setfillstyle(SOLID_FILL,WHITE);                                             //halate sadeye sefid ra baraye por kardane ashkal entekhab mikonad

    for(i=0;i<num;i++)                                                          //avangha ra momas bar khatkesh rasm mikonad
   	{
    	size=20-10*i/(num-1);
        l = li-i*deltal;
		x=-l*sin(teta);
        y=sqrt(l*l-x*x);
       	m=400+x/li*400+(20-size)*cos(teta);
		n=y/li*400+(20-size)*sin(teta);
		fillellipse(m,n,size,size);
		line(400,0,m,n);
    }

    outtextxy (270, 500,"created by abbas momtaz student of D.r Taheri");       //matne ra namayesh midahad
    delay(4000);                                                                //4 sanie sabr mikonad
    clearviewport();                                                            //safe ra pak mikonad



	for(t=0;t<=time;t+=0.04)                                                    //motore aslie barname
	{
 		outtextxy (688,570-(num-1)*8,"Top screen");                             //in ghesmat "top screen" & "3D screen" & "T" & "D.T" ra minevisad
		outtextxy (580,497,"3D screen");
		line(725,590,725,590-(num-1)*8);
		outtextxy (5,3,"T");
		outtextxy (24,3,"D.T");

		m=t/time*575+20;                                                        //nemudare zaman va estekak ra rasm mikonad
		n=t/deathtime*575+20;
		line(8,20,8,m);
		line(34,20,34,n);


		for(i=0;i<num;i++)
		{
			l=li-i*deltal;			                                            //tule avang ha ra baraye har avang hesab mikone
			x=-l*sin(teta)*cos(w[i]*t);     	                                //mokhtasate x avang ha ra hesab mikone
            x=x-x*t/deathtime;                                                  //estekak ra vared mikonad
            if(t>deathtime){x=0;}                                               //estekak ra vared mikonad
            y=sqrt(l*l-x*x);				                                    //mokhtasate y avang ha ra ba tavajo be x hesab mikone
			m=400+x/li*400;                                                     //mokhtasat ra az double be int barmigardanad
			n=y/li*400;                                                         //mokhtasat ra az double be int barmigardanad
			size=20-10*i/(num-1);					                            //size avang ha ro tanzim mikone
			fillellipse(m,n,size,size);	                                        //avang ha ra rasm mikonad
			line(400,0,m,n);                                                    //nakhe avang ha ra rasm mikonad

			m=725+x/li*50;                                                      //in ghesmat "top screen" ra hesab va rasm mikonad
			n=590-i*8;
			fillellipse(m,n,3,3);
			line(725,n,m,n);

			m=625-i*3+x/li*50;                                                  //in ghesmat "3D screen" ra hesab va rasm mikonad
			n=540+y/li*50;
			fillellipse(m,n,3,3);
			line(625-i*3,515,m,n);

		}

        mp=0;
        for(i=0;i<num;i++)                                                      //in ghesmat halat haye khas ra tashkhis midahad
        {
             for(m=0;m<num;m++)
             {
                   if (fabs(sin(w[i]*t)-sin(w[m]*t))<0.025){mp++;}
             }
        }
        if (mp>=2.5*num){fillellipse(700,30,3,3);}


        delay(25);                                                              //25 m sec takhir ijad mikonad
		clearviewport();                                                        //saffe ra pak mikonad

	}
    outtextxy (270, 300,"created by abbas momtaz student of D.r Taheri");
    outtextxy (270, 350,"        program has finished successfully    ");
	cin>>time;
	return 0;
}



