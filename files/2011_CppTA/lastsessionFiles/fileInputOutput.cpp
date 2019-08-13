/*********************************************************************
Copyright (C) :    University of Michigan
Project:           ENG- Class example
File:              fileInputOutput.cpp
Purpose:           Demonstrates reading from and wriyting to files
Compiler:          g++
Start Date:        3/4/2001
Use input1.txt as input file and any of the .txt, .doc or .xls
as output file. The program will get the data from the input
file and write it back into the output file.
Written By: Bahram Taheri
*********************************************************************/
//
//File: fileInputOutput.cpp
#include <fstream> // step I: include fstream header file
#include <vector>
#include <conio.h>
#include <iomanip>

using namespace std;

int main(void)
{  ifstream myInputFile; // step II: Declare filestream variable
                         //          named myInputFile
   ofstream myOutputFile;

   cout << "What filename do you want to read from: ";
   char fileNameIn[20]; // 1D array of chars
   cin >> fileNameIn;
   cout << "What filename do you want to write to: ";
   char fileNameOut[20]; // 1D array of chars
   cin >> fileNameOut;

   myInputFile.open(fileNameIn);//step III: Associate the filestream
                              // variables with the input/output
                              // sources, called opening the file
                              // using the stream member function
                              // .open(sourceName, fileOpeningmode)
    cout << "myInputFile.fail() = " << myInputFile.fail()<<endl;
    getch();

   if (myInputFile.fail())
   {  // File could not be opened
      cerr << "File called " << fileNameIn << " could not be opened.\n";
      getch();
      return 1; // Return to O/S with abnormal return code
   }
   else
      cout << "File called " << fileNameIn << " was successfully opened.\n\n\n";


   myOutputFile.open(fileNameOut);//step III: Associate the filestream
                              // variables with the input/output
                              // sources, called opening the file
                              // using the stream member function
                              // .open(sourceName, fileOpeningmode)
    cout << "myOutputFile.fail() = " << myOutputFile.fail()<<endl;
    getch();

   if (myOutputFile.fail())
   {  // File could not be opened
      cerr << "File called " << fileNameOut << " could not be opened.\n";
      getch();
      return 1; // Return to O/S with abnormal return code
   }
   else
      cout << "File called " << fileNameOut << " was successfully opened.\n\n\n";



   bool keepReading = true; // Keep reading if true
   do{
      float x, y; // Two floats
      myInputFile >> x >> y; //step IV: Use the filestream variable
                             // with << or >> operators to insert
                             // or extract data
      myOutputFile << x << "\t\t" << y << endl;
      cout<< "Press any key to continue!";
      getch();
      if (myInputFile.eof()) keepReading = false; // End of file <CNTL>-D detected
      else cout << setw(6) << x << setw(6) << y << endl;
   }while(keepReading);

   cout << "End of input detected\n";
   myInputFile.close(); //Step V: Disconnect the stream from the
                        // file and close the file.
   myOutputFile.close();
   getch();
   return 0;
}
