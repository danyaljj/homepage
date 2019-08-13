//String
//Syntax for .substr(startPos,Length) function
//Try different starting positions and lengths
#include <iostream>
#include <string>
#include <conio>

//using namespace std; 	//introduces namespace std
int main()
{   
   string initials;      //declarations
   string first;
	string middle;
	string last;
  
	cout<<"Enter your full name (First, Middle, Last)"
   <<endl;   //Output the question
	
   cin>>first>>middle>>last;                               //Input each part of the name
   initials=first.substr(0,1)+"."+middle.substr(0,1)
   + "." +last.substr(0,1)+ ".";   //Get first initial of each part of name
   cout<<"Your initials are "<<initials<<"\n";           //Output the correct initials
	
	getch();
	return EXIT_SUCCESS;   //returns int
	
	
}