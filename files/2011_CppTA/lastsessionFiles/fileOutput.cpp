/*********************************************************************
Copyright (C) :    University of Michigan
Project:           ENG- Class example
File:              fileOutput.cpp
Purpose:           Demonstrates writing to files
Compiler:          g++
Start Date:        3/4/2001
Choose .txt, .doc and .xls type of files
In the output for .xls remove the \t from the line below and see what happens
     else myOutputFile << x << "\t" << y << endl;
*********************************************************************/
//Use first output1.txt as the output file. Use <CTRL> z to indicate
//end of file
//Use output1.doc as the output file. For end of file, without
//going to the next line you should type <CTRL> z to stop
//Use output1.xls as the output file and end data stream with
//<CTRL> z


//File: fileOutput.cpp
#include <fstream> //Step I:Include headerfile fstream in the prog
#include <vector>

using namespace std;

int main(void)
{  ofstream myOutputFile; //Step II: Declaring the stream variable
   
   cout << "What filename do you want to write to: ";
   char fileName[20]; // 1D array of chars
   cin >> fileName;
   
   myOutputFile.open(fileName); //Step III: Connect the file stream
                                //variable to the output file
   
   if (myOutputFile.fail())
   {  // File could not be opened
      cerr << "File called " << fileName << " could not be opened.\n";
      return 1; // Return to O/S with abnormal return code
   }
   else
      cout << "File called " << fileName << " was successfully opened.\n";
   
   bool keepReading = true; // Keep reading if true
   do{
      cout << "Enter two floats? ";
      float x, y; // Two input floats
      cin >> x >> y;;
      if (cin.eof()) keepReading = false; // End of file <CNTL>d detected (UNIX)
                                          // End of file <CNTL>z Windows
      else myOutputFile << x << "\t" << y << endl; //Step IV:
                          //Use the filestream variable with
                          // << to insert data into the data file
   }while(keepReading);

   cout << "End of input detected\n";
   myOutputFile.close(); //Step V: Disconnect the filestream variable
                         //from the output file
   
   return 0;
}
