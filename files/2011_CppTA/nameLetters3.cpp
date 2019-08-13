//String
//Introducing .length() function
//Ask why there are two periods at the end of prog's output.
//C++ doesn't print an error message when it reaches an
//index beyond the end of string variables.
#include <iostream>
#include <string>
#include <conio>
//using namespace std; 	//introduces namespace std
int main()
    {
    string name;          //declare variables
    int pos, numOfCharacters;

	
	cout<<"Enter your first name"<<endl;
   //output the question.
    cin>>name;                                                         //input the name
    numOfCharacters=name.length();
    cout << "Length of your name is: "
         << numOfCharacters << endl;                                         //find length of characters
    cout<<"The letters of your name are ";
   	 for (pos=0;pos<=numOfCharacters;pos++)                                //loop to go through all letters
   	 {
    	   cout<<name.substr((pos+2),2)<< ".";
         //Why there are two periods at the end?
         //Try changing the length of substring to 2.
         getch();
       }

	getch();
	return EXIT_SUCCESS;                                              //exit
	
	
}