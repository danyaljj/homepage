/*********************************************************************
Copyright (C) :    University of Michigan
Project:           ENG- Class example
File:              structure3.cpp
Purpose:           Sorting structures
Compiler:          g++
Start Date:        10/30/00
*********************************************************************/

//File: structure3a.cpp
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<cstdlib>

// Define a structure called Student
const int maxNameLength = 10;
struct Student
{  char name[maxNameLength];
   int section;
   float grade;
};


//BaT switch function called by reference.
bool switchStruct(struct Student& a, struct Student& b)
{  struct Student temp = a; a = b; b = temp; // Switch a and b
   return false;
}



//BaT Sorting function
void sortStruct(vector<struct Student>& list, bool n, bool s, bool g)
{  bool sorted;
//BaT Sorting according to whichever bool-Value nAME, sECTION, or gRADE is true.
//BaT Name ascending order of first letter of the name
//BaT Section, ascending order
//BaT Grade, Descending order
   if (n)
   {  do
      {  sorted = true;
         for (int i = 0; i < list.size() - 1; i = i + 1)
         {  string string1 = list[i].name;
            string string2 = list[i+1].name;
            if (string1 > string2)
               sorted = switchStruct(list[i],list[i+1]);
         }//BaT By the end of this internal for-loop, if even a single exchange occurs,
		  //BaT switchStruct function will return a false value for sorted, which in turn
		  //BaT will make !sorted (not sorted) true, and do-while will do another loop
		  //BaT until no exchange occurs within a loop, switchStruct would not be called,
		  //BaT sorted will remain true, and !sorted becomes false. 
      }while (!sorted);
   }
   else if (s)
   {  do
      {  sorted = true;
         for (int i = 0; i < list.size() - 1; i = i + 1)
            if (list[i].section > list[i+1].section)
               sorted = switchStruct(list[i],list[i+1]);
      }while (!sorted);
   }
   else if (g)
   {  do
      {  sorted = true;
         for (int i = 0; i < list.size() - 1; i = i + 1)
            if (list[i].grade < list[i+1].grade)
               sorted = switchStruct(list[i],list[i+1]);
      }while (!sorted);
   }
   return;
}
   
   
int main(void)
{  cout << "How many students in the class? ";
   int nStuds;
   cin >> nStuds;

//BaT Example of a VECTOR STRUCT
//BaT The Student struct is defined at the top, global area.
//BaT Syntax:  vector<struct type> vectorName(size);
   vector<struct Student> myClass(nStuds);
   
//BaT Loop for initialization of every property of all structs in the vector.
   for (int i = 0; i < nStuds; i = i + 1)
   {  myClass[i].section = 200 + rand()%10;
      myClass[i].grade = 0.1*(rand()%1001);

//BaT nameLength is defined in global area as int 10.
      int nameLength = 2 + rand()%(maxNameLength - 2);
      for (int j = 0; j < nameLength; j = j + 1) 
         myClass[i].name[j] = 97 + rand()%26;
//BaT ASCII characters a-z have integer equivalents 97-122
//BaT In the above code line, random names (2-9)-charcter long are assigned.


      myClass[i].name[nameLength - 1] = '\0';  //Last charcter becomes a ",".
      myClass[i].name[0] = myClass[i].name[0] - 32; //BaT First character capitalized.
      cout << setw(maxNameLength) << myClass[i].name << ", " 
           << myClass[i].section << ", " 
           << myClass[i].grade << "\n";
   }


//BaT Here the user decides on option of sorting.
   bool sortByName = false;
   bool sortBySection = false;
   bool sortByGrade = false;
   cout << "Sort by name (0 (no) or 1 (yes))? ";
   cin >> sortByName;
   if (!sortByName)
   {  cout << "Sort by section (0 (no) or 1 (yes))? ";
      cin >> sortBySection;
      if (!sortBySection)
      {  cout << "Sort by grade (0 (no) or 1 (yes))? ";
         cin >> sortByGrade;
      }
   }
   

//BaT Call for sorting function, by refernce for myClass==>list vactor
//BaT and by value for sortByName==>n, sortBySection==>s, and sortByGrade==>g   
   sortStruct(myClass, sortByName, sortBySection, sortByGrade);

//BaT Printing the requested sorted data
   for (int i = 0; i < nStuds; i = i + 1)
      cout << setw(maxNameLength) << myClass[i].name << ", " 
           << myClass[i].section << ", " 
           << myClass[i].grade << "\n";
   return 0;
}

