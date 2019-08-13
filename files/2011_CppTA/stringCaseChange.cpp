//Write a program which accepts your First Middle Last
//Name. Has a function which appends these strings and
//has another function which takes output of the first function,
//and changes the cases of all the letters in the appended
//string as a vector of chars.
//Note that a=97 and A=65.
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

using namespace std;

string appendNames(string&firstN, string& middleN,
string& lastN, string appended)
{
   cout << "Appended name in the beginning of the func is: "
        << appended << endl;
   appended = firstN.append(middleN);
   appended = appended.append(lastN);
   return appended;
}
void caseChangeFunc(string& allInOne)
{
   int size = allInOne.size();
   cout <<"Appended size is: " << size << endl;
   for (int i=0; i<size; i++)
   {
      int temp = allInOne[i];  //storing a char as an int
      if(temp>=97 && temp<=122)
      {
         temp = temp - 32;
         allInOne[i] = temp; //replacing an int as a char
                             //member of a string
      }
      //Khosravani Q: Why else if?
      else if(temp<=90 && temp>=65)
      {
         temp = temp + 32;
         allInOne[i] = temp;
      }
   }
   cout << "Changed form of Appended Name is:\n"
        <<allInOne <<endl;

}

int main(void)

{  string First, Middle, Last, allInOne;
   vector <char> initials;
   cout <<"Enter your complete name, First Middle Last:" << endl;
   cin >> First >> Middle >> Last;
   cout <<"First Name: " <<First<<"\nMiddle: "
   <<Middle<<"\nLast: "<<Last << endl;
   //Note here that we have sent allInOne by value to the
   //function before initializing it. So, it should have
   //a void value before being sent to the func. and in
   //the beginning of the function.
   cout << "allInOne before the function is:" << allInOne
        << endl;
   allInOne = appendNames(First,Middle,Last,allInOne);
   cout << allInOne << endl;
   caseChangeFunc(allInOne);
   getch();
   return 0;
}

