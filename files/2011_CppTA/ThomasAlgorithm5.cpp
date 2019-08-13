#include <iostream>
#include <conio>
#include <vector>

using namespace std;

const int N =5;

int main(void)
{
   double e[N+1], f[N+1], g[N+1], r[N+1], x[N+1];

   for(int i=1; i<=N; i++)
   {
      e[i]=1;
      f[i]=2;
      g[i]=1;
   }
   r[1]=4;
   r[2]=8;
   r[3]=12;
   r[4]=16;
   r[5]=14;
   for(int j=2; j<=N; j++)
   {
      e[j]=e[j]/f[j-1];
      f[j]=f[j]-e[j]*g[j-1];
      cout << "Before r["<<j<<"]=" << r[j]<<"  e["<<j<<"]="<<e[j]
           <<"  r["<<j-1<<"]="<<r[j-1]<<endl;
      r[j]=r[j]-e[j]*r[j-1];
      cout << "After   r["<<j<<"]=" << r[j] << endl<<endl<<endl;
      cout << "e["<<j<<"]="<<e[j]<<endl;
      cout << "f["<<j<<"]="<<f[j]<<endl;
      cout << "r["<<j<<"]="<<r[j]<<endl<<endl;
   }
   x[N]=r[N]/f[N];
   cout <<"X["<<N<<"]="<<x[N]<<endl<<endl;
   for (int m=N-1; m>=1; m--)
   {
      x[m]=(r[m]-g[m]*x[m+1])/f[m];
   }
   for(int n=1; n<=N; n++)
      cout << "X[" << n << "]=" << x[n] << endl;

   getch();
   return 0;
}
