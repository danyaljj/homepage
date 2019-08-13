/*                               /----------------------\
											|Pooria Panahifar      |
                                 |Mechanical Engineering|
                                 |Bachlor of Science    |
                                 |C++ Project 1         |
                                 |Instructor:Dr.B.Taheri|
                                 \----------------------/
	This Program is a good introduction for STRUCTURES in C++. It also sorts
data in the Alphabetic order. At the end the reader will be surprised by
understanding the method I used for printing out the informations. This program
was written in 160 lines and is a modified version of the program I received
from Dr. Taheri.*/

#include <iostream.h>
#include <conio.h>
#include <string>
#include <vector.h>
#include <iomanip.h>

using namespace std;

struct student
{
    string FirstName, LastName; //name of student
    string SN; // Student's number
    string major, degree ;
};

int main()
{
   int i, j;   // declaration
   cout << "This Prog. is an intro to Structs." << endl;
   cout << "You will enter info about tudents\n";
   cout << "And this prog will sort th data alphabetically.\n" << endl;
   cout << "Enter the number of students:\n";
   cin >> j;

   cout << "From this point you have to enter your data. Be careful that you "
   	  << "can only enter one word for each data. Anyhow, remember that do "
        << "not add spaces between parts of a word. For example: instead of "
        << "writing Mech Eng for major, you can write Mech_Eng.\n";

   student all[5000];  // assuming all from structure "student" 5000 spaces
   for (i=0; i<j; i++) // Using a loop for numbering the ALL's subsets
   {
      cout << "(" << (i+1) << ")" << endl;

   	cout << "Enter student's first name and last name in this form: "
      	  << "FirstName LastName\n";
      cin >> all[i].FirstName >> all[i].LastName;

      cout << "Enter student number\n";
      cin >> all[i].SN;

      cout << "Enter student's major\n";
      cin >> all[i].major;

      cout << "Enter student's degree\n";
      cin >> all[i].degree;
   }

   cout<<"\n"<<endl;

/*   string nameslist[500];

   for (i=0; i<j; i++)
   {                                    //With this part you can transform
   	nameslist[i]=students[i].name;    // a specific sequence to an array
      cout<<nameslist[i]<<endl;
   }
*/
   string nTemp1, nTemp2, nTempM, nTempD, nTempN;  // Declaration

   // The begining of the operation of sorting

   for (i=1; i<j; i++)
   {
		//the new value to be inserted into a temporary location
   	nTemp2 = all[i].LastName;
      nTemp1 = all[i].FirstName;
      nTempM = all[i].major;
      nTempD = all[i].degree;
      nTempN = all[i].SN;

   	// k is the index of the number to the left of the iCv.
   	int k;
      for (k=i-1; k>=0 && all[k].LastName>nTemp2; k--)
      {
      	all[k+1].LastName = all[k].LastName;
         all[k+1].FirstName = all[k].FirstName;
         all[k+1].major = all[k].major;
         all[k+1].degree = all[k].degree;
         all[k+1].SN = all[k].SN;
      }
      all[k+1].LastName = nTemp2;
      all[k+1].FirstName = nTemp1;
      all[k+1].major = nTempM;
      all[k+1].degree = nTempD;
      all[k+1].SN = nTempN;
   }
   // The end of the operation of sorting
   cout << endl << endl << endl << endl << endl << endl << endl;

   int code1=185, code2=186, code3=187, code4=188, code5=200, code6=201, code7=202
   	, code8=203, code9=204, code10=205, code11=206;
   char symbol1, symbol2, symbol3, symbol4, symbol5, symbol6, symbol7, symbol8
   	, symbol9, symbol10, symbol11;
   symbol1=code1;
   symbol2=code2;
   symbol3=code3;
   symbol4=code4;
   symbol5=code5;    // Declarations and assignments for Output
   symbol6=code6;
   symbol7=code7;
   symbol8=code8;
   symbol9=code9;
   symbol10=code10;
   symbol11=code11;

   for (i=0; i<j; i++)   // A Loop for Printing the ordered Subsets of struct
   {
   	cout << "\t" << "(" << (i+1) << ")\n\n"
      	  << symbol6; for(int e=0;e<12;e++) cout<<symbol10; cout<<symbol8;
           for(int e=0;e<22;e++) cout<<symbol10; cout<<symbol3<<endl

           << symbol2 << " First Name " << symbol2 << " " << setw(21-all[i].
           FirstName.length()) << all[i].FirstName << " " << symbol2 << endl

           << symbol9; for(int e=0;e<12;e++) cout<<symbol10; cout<<symbol11;
           for(int e=0;e<22;e++) cout<<symbol10; cout<<symbol1<<endl

           << symbol2 << " Last Name  " << symbol2 << " " << setw(21-all[i].
           LastName.length()) << all[i].LastName << " " << symbol2 << endl

           << symbol9; for(int e=0;e<12;e++) cout<<symbol10; cout<<symbol11;
           for(int e=0;e<22;e++) cout<<symbol10; cout<<symbol1<<endl
           << symbol2 << " Student N# " << symbol2 << " " << setw(21-all[i].
           SN.length()) << all[i].SN << " " << symbol2 << endl

           << symbol9; for(int e=0;e<12;e++) cout<<symbol10; cout<<symbol11;
           for(int e=0;e<22;e++) cout<<symbol10; cout<<symbol1<<endl

           << symbol2 << "    Major   " << symbol2 << " " << setw(21-all[i].
           major.length()) << all[i].major << " " << symbol2 << endl

           << symbol9; for(int e=0;e<12;e++) cout<<symbol10; cout<<symbol11;
           for(int e=0;e<22;e++) cout<<symbol10; cout<<symbol1<<endl

           << symbol2 << "   Degree   " << symbol2 << " " << setw(21-all[i].
           degree.length()) << all[i].degree << " " << symbol2 << endl

           << symbol5; for(int e=0;e<12;e++) cout<<symbol10; cout<<symbol7;
            for(int e=0;e<22;e++) cout<<symbol10; cout<<symbol4<<endl;

      cout << endl << endl ;

      int time;
      for (time=0; time<900000000; time++)
      	time = time + 1;  // A loop for making the operation to take more time
      time = 0;


   }

   getch();
   getch();
   return 0;

}
// There had been no meaning of C++ for me if Dr.B.TAHERI wasn't my professor.
