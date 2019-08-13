#include <stdio.h>
#include <conio.h>
#include <math.h>

void main(void)
{
   int i, j, flag;
   int iter = 0;
   double A[4][4], B[4], Xo[4], Xn[4], rhside[4], EPS[4];
   FILE *inptr2;
   FILE *outptr2;
   inptr2 = fopen("input.txt","r");
   outptr2 = fopen("matrix2.txt","wt");

   for (i=0; i<4; i++)
      for (j=0; j<4; j++)
         fscanf(inptr2,"%lf\n", &A[i][j]);

   for (i=0; i<4; i++)
      fscanf(inptr2,"%lf\n", &B[i]);

   for (i=0; i<4; i++)
      rhside[i] = B[i];


label1: printf("\nPlease initialize X[4], the unknown vector, start from row 1.\
        \nA good starting value to check your program's performance is X(i)=1.0\
        \nPress enter after the last entry: \n");

   for (i=0; i<4; i++)
      scanf("%lf", &Xo[i]);
   printf("\n");

   do
   {
      for (i=0; i<4; i++)
         rhside[i] = B[i];
      iter = iter +1;

      for (i=0; i<4; i++)
      {
         printf("\n| ");
         for(j=0; j<4; j++)
            printf("%3.1lf  ", A[i][j]);
            printf(" | | ");
            printf("%7.4lf | | %3.1lf |", Xo[i], B[i]);
      }

      for (i=0; i<4; i++)
      {
         for (j=0; j<4; j++)
         {
            if (j != i)
               {
               rhside[i] = rhside[i] - A[i][j]*Xo[j];
               }
         }
         Xn[i] = rhside[i]/A[i][i];
         if (Xn[i] == 0.)
            {
            printf ("The denominator in calculation of error\
            \n, i.e, X[%2d] became equal zero.  Iterations fail.\
            \nProgram is going to prompt you to start from a\
            \ndifferent set of initial guesses. This happened\
            \nat iteration number %2d",i,iter);
            goto label1;
            }
         EPS[i] = fabs((Xn[i] - Xo[i])/Xn[i])*100;
         Xo[i] = Xn[i];
         printf ("%7.4lf   %7.4lf\n",Xn[i], EPS[i]);
        }
        flag = 0;
        for(i=0; i<4; i++)
        {
           if(EPS[i] > .01)
           {
           flag = 1;
           break;
           }
        }
        }while ( flag );
        printf("Program converged at iteration number = %2d",iter);
        getch();
        fclose(outptr2);
}


