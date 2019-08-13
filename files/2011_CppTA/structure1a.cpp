/*********************************************************************
Copyright (C) :    University of Michigan
Project:           ENG- Class example
File:              structure1.cpp
Purpose:           An example of call-by-value and structures
Compiler:          g++
Start Date:        10/30/00
*********************************************************************/

//File: structure1a.cpp
#include<iostream>
#include<string>

// Define a structure called Student
//BaT Defined in the global area to be common between the function and main
struct Student
{  string name;
   int section;
   float grade;
};


//BaT Note that this is call-by-value! No & signs. So, an actual copy of
//BaT Dan and Jan properties will be made in Student variables a and b.
void switchStruct(struct Student a, struct Student b)
{  cout << "\nIn function, before call to function\n";
   cout << "1st structure is: " << a.name << ", " 
                                << a.section << ", "
                                << a.grade << "\n";
   cout << "2nd structure is: " << b.name << ", " 
                                << b.section << ", "
                                << b.grade << "\n";

   struct Student temp = a; a = b; b = temp; // Switch a and b

   cout << "\nIn function, after call to function\n";
   cout << "1st structure is: " << a.name << ", " 
                                << a.section << ", "
                                << a.grade << "\n";
   cout << "2nd structure is: " << b.name << ", " 
                                << b.section << ", "
                                << b.grade << "\n";
   return;
}

int main(void)
{  struct Student
      Dan = {"Smith, Dan", 210, 79.8},
      Jan = {"Brown, Jan", 201, 89.3};

   cout << "\nIn main, before call to function\n";
   cout << "Dan is: " << Dan.name << ", " 
                      << Dan.section << ", "
                      << Dan.grade << "\n";
   cout << "Jan is: " << Jan.name << ", " 
                      << Jan.section << ", "
                      << Jan.grade << "\n";

   switchStruct(Dan,Jan);

   cout << "\nIn main, after call to function\n";
   cout << "Dan is: " << Dan.name << ", " 
                      << Dan.section << ", "
                      << Dan.grade << "\n";
   cout << "Jan is: " << Jan.name << ", " 
                      << Jan.section << ", "
                      << Jan.grade << "\n";
   return 0;
}

