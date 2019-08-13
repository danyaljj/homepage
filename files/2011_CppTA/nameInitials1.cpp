//Written: Winter 2003
//String
//Gets your name's initials

#include <iostream>
//#include <stdlib>          //Replaces  cstdlib in g++
#include <string>				// Required to add the string support in
#include <conio>
//using namespace std;

int main(void)
{
	string first, middle, last;
	
	
	// METHOD ONE
	cout << "Please input your name (First Middle Last):"
        << endl;
			

	// find the initials and print
	//cin >> first >> middle >> last;
   cin >> first;
   cin >> middle;
   cin >> last;
	cout << "Your First Name is: " << first << endl;
   cout << "Your Middle Name is: " << middle << endl;
   cout << "Your Last Name is: " << last << endl;
	cout << "\nYour initials are the following:" << endl;
	
	cout << first[0] << "." << middle[0] << "." << last[0]
        << ".";
	
	getch();
	return EXIT_SUCCESS;
}


