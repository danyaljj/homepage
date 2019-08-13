/*********************************************************************
Copyright (C) :    University of Michigan
Project:           ENG101 - Class example
File:              vectors.cpp
Purpose:           Randomly populating a vector in a given range
Compiler:          g++
Start Date:        02/18/03
Written By:        Bahram Taheri
*********************************************************************/
#include <iostream>
#include <vector>
#include <stdlib>
#include <time>
#include <conio>

using namespace std;

int main(void)
{
   cout << "Enter the length(size) of an int vector: " ;
   int N;
   cin >> N;
   vector<int> v(N);
   cout << "Enter Min and Max value of the vector range:" ;
   int lowerBound , upperBound;
   cin >> lowerBound >> upperBound;
   int range = upperBound - lowerBound;
   srand(time(NULL));
//   for (int i=0; i<v.size(); i++)
//   {
//      v[i] = (range+1)*rand()/RAND_MAX+lowerBound;
//      cout <<"V["<<i<<"] = " << v[i] << endl;
//   }
   for (int i=0; i<v.size(); i++)
   {
      v[i] = rand()%(range+1)+lowerBound;
      cout <<"V["<<i<<"] = " << v[i] << endl;
   }

   getch();
   return 0;
}
