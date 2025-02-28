/*********************************************************************
Copyright (C) :    University of Michigan
Project:           ENG- Class example
File:              fileInput.cpp
Purpose:           Demonstrates reading from files
Compiler:          g++
Start Date:        3/4/2001

Note: First use input1.txt and then input1.doc, input.xls and input2.txt input file.
Then choose the file output1.doc as input. Even though this file is generated by
our outputfile C++ program, still our C++ program cannot recognize the numbers in it.
*********************************************************************/

//File: fileInput.cpp
#include <fstream> // step I: include fstream header file
#include <vector>
#include <conio.h>
#include <iomanip>

using namespace std;

int main(void)
{  ifstream myInputFile; // step II: Declare filestream variable
                         //          named myInputFile
   
   cout << "What filename do you want to read from: ";
   char fileName[20]; // 1D array of chars
   cin >> fileName;
   
   myInputFile.open(fileName);//step III: Associate the filestream
                              // variables with the input/output
                              // sources, called opening the file
                              // using the stream member function
                              // .open(sourceName, fileOpeningmode)
    cout << "myInputFile.fail() = " << myInputFile.fail()<<endl;
    getch();

   if (myInputFile.fail())
   {  // File could not be opened
      cerr << "File called " << fileName << " could not be opened.\n";
      getch();
      return 1; // Return to O/S with abnormal return code
   }
   else
      cout << "File called " << fileName << " was successfully opened.\n\n\n";
   
   bool keepReading = true; // Keep reading if true
   do{
      float x, y; // Two floats
      myInputFile >> x >> y; //step IV: Use the filestream variable
                             // with << or >> operators to insert
                             // or extract data
      cout<< "Press any key to continue!";
      getch();
      if (myInputFile.eof()) keepReading = false; // End of file <CNTL>-D detected
      else cout << setw(6) << x << setw(6) << y << endl;
   }while(keepReading);

   cout << "End of input detected\n";
   myInputFile.close(); //Step V: Disconnect the stream from the
                        // file and close the file.
   getch();
   return 0;
}
