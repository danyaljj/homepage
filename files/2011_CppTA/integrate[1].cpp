/*********************************************************************
Copyright (C) :    University of Michigan
Project:           ENG101 - Class example
File:              integrate.cpp
Purpose:           Integrates a function of x in three different ways,
                   shows how to provide a vactor to a function
Compiler:          g++
Programmer:        Alex Bielajew
Start Date:        10/28/02
*********************************************************************/

//File: integrate.cpp
#include <iostream>
#include <math>
#include <vector>
#include <string>
#include <conio>

using namespace std;

void makeMyFunction
(  vector<double>& f, //On return will contain a vector of f(x[i]) = exp(x[i])
   vector<double>& x  //On return, will contain the x[i] vector
)
{  cout << "Number of points in the integration mesh: ";
   int meshSize;
   cin >> meshSize;
   vector<double> F(meshSize), X(meshSize); // Working vectors
   for(int i = 0; i < meshSize; i = i + 1)
   {  X[i] = static_cast<double>(i)/(meshSize - 1); //meshSize - 1 rectangles
      F[i] = exp(X[i]);
   }
   f = F; //Set up f for the return
   x = X; //Set up x for the return
   return;
}

double integrateLeft(const vector<double>& f, const vector<double>& x)
{  double sum = 0;
   for (int i = 0; i < f.size() - 1; i = i + 1)
      sum = sum + f[i]*(x[i + 1] - x[i]);
   return sum;
}

double integrateRight(const vector<double>& f, const vector<double>& x)
{  double sum = 0;
   for (int i = 0; i < f.size() - 1; i = i + 1)
      sum = sum + f[i + 1]*(x[i + 1] - x[i]);
   return sum;
}

double integrateMiddle(const vector<double>& f, const vector<double>& x)
{  double sum = 0;
   for (int i = 0; i < f.size() - 1; i = i + 1)
      sum = sum + 0.5*(f[i] + f[i + 1])*(x[i + 1] - x[i]);
   return sum;
}

void printResult
(
   const string comment,  //Comment to start off the output line
   const double integral, //Result of the integration
   const double exact     //The known exact result
)
{
    cout << 
      comment << integral << " cf " << exact 
      << " diff = " << integral - exact << "\n";
  return;
}

int main(void)
{  
   vector<double> f,x;
   makeMyFunction(f,x);

   double integral = integrateLeft(f, x);
   printResult("left = \t\t", integral, exp(1.0) - 1.0);
 
   integral = integrateRight(f, x);
   printResult("right = \t", integral, exp(1.0) - 1.0);
 
   integral = integrateMiddle(f, x);
   printResult("midpoint = \t", integral, exp(1.0) - 1.0);
   getch();
   return 0;
}
