/*********************************************************************
Copyright (C) :    University of Michigan
Project:           ENG- Class example
File:              structure0.cpp
Purpose:           An example of manipulating structures
Compiler:          g++
Start Date:        10/30/00
*********************************************************************/

//File: structure0a.cpp
#include<iostream>
#include<string>

// Define a structure called Student
//BaT Defining basically means you are specifying which kind of
//BaT data is aggregated in the data struct.  We don't give the
//BaT real instances of data here.
struct Student
{  string name;
   int section;
   float grade;
};
//BaT Declaration and initialization of real instances of two structs 
int main(void)
{  struct Student
      Dan = {"Smith, Dan", 210, 79.8},
      Jan = {"Brown, Jan", 201, 89.3};

//BaT struct.property syntax is used to refer to various data
   cout << "Dan's full name is: " << Dan.name << "\n";
   cout << "Jan's full name is: " << Jan.name << "\n";

   cout << Dan.name << " is in section: " << Dan.section << "\n";
   cout << Jan.name << " is in section: " << Jan.section << "\n";

   // Jan takes Dan's last name
   Jan.name = "Smith, Jan";
   cout << "Jan's full name now is: " << Jan.name << "\n";

   // Jan moves to Dan's section 
   Jan.section = Dan.section;
   cout << Jan.name << " is now in section: " << Jan.section << "\n";

   // Switch Jan and Dan completely
   cout << "Dan and Jan swap identities...\n";
//BaT Declaration and initialization of a new temporary struct Student.
//BaT Important: Note that simple assignment of one struct to another
//BaT by name transfers all the properties at once.
   struct Student Temp = Jan;
   Jan = Dan;
   Dan = Temp;
   cout << "Dan is: " << Dan.name << ", " 
                      << Dan.section << ", "
                      << Dan.grade << "\n";
   cout << "Jan is: " << Jan.name << ", " 
                      << Jan.section << ", "
                      << Jan.grade << "\n";

   return 0;
}
