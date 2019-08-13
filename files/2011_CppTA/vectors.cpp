/*********************************************************************
Copyright (C) :    University of Michigan
Project:           ENG101 - Class example
File:              vectors.cpp
Purpose:           Simple vector creation
Compiler:          g++
Start Date:        02/18/03
Written By:        Bahram Taheri
*********************************************************************/
#include <iostream>
#include <vector>
#include <conio>

using namespace std;

int main(void)
{  vector<double> v(3);

   v[0] = 8;
   v[1] = 6;
   v[2] = 4;
   int size = v.size();
   cout <<"The Vector Size is: " << size << endl;
//for (int i=0; i<v.size(); i++)  this form can be used too
//Remember to explain the case i<=size
   for (int i=0; i<size; i++)
   {
      cout <<"V["<<i<<"] = " << v[i] << endl;
   }   

   getch();
   return 0;
}
