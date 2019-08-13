/******************************************
* name: M.Zoghi-R.Rahimi                  *
* st no:8523027-8523029                   *
* date:85.11.1                            *
* section:1-2:30                          *
* This program is planned to search a     *
* word in a file and then chang the color *
* of it.                                  *
******************************************/

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
int main(void)
{
   cout<<"name: M.Zoghi-R.Rahimi /st no:8523027-8523029/ date:85.11.1  /section:1-2:30 "<< endl;
   ifstream myInputFile;
   cout << "What filename do you want to read from: ";
   char fileName[20];
   cin >> fileName;  // take the name of the file.
   myInputFile.open(fileName);  // open the file .
   if (myInputFile.fail())  // check if it was opened.
   {
		cerr << "File called " << fileName << " could not be opened.\n";
      getch();
      return 1;
   }
   else  // now it has been opened
      cout << "File called " << fileName << " was successfully opened.\n";
   cout<<"which word do you want to search?"<<endl;
   string y;  // y is a variable that store the word that the user wants to search.
   cin>>y;
   int letter=y.length();  // define howmany letters the word has.
   bool keepReading = true; // declare a boolian variable to make sure that we have still have data to check.
   bool n =true ;//declare a boolian variable to chech if any word in file detected or not.
   do{
      string x ;// a variable to accept data from file.
      myInputFile >> x ;
		int a=x.length( ); //define howmany letters the word in file has.
 		int pos=0; // the situation of the letters in word that we want to search
      int i= 0,t=1 ,m=0 ; // declare "m" to check if the data is the same as given word or not .
      while( i<a )   // in this loop it checks letter by letter to find a word that has the given word.
				{
 				if (y[pos]==x[i])
            		{
						if (pos<letter-1)
								pos=pos+1;
						else
								{
								 textcolor(10);
							    i=a ;
                         //change the color of x.
                         cprintf("%s", x);
				             cout<<" ";
                         m=1 ;
                         n=false ;
                         }
                  }
				else
						{
						pos=0 ;
						}
				i=i+1;
				}
          if(m==0 )
           cout<< x<<" ";
		if(myInputFile.eof())
		     keepReading = false;
   }while(keepReading);
   if(n) // if it has not find any word.
       cout<<"Your word wasn't found"<<endl;
   myInputFile.close();
   getch();
   return 0;
}