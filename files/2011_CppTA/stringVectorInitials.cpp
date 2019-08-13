//File: string1.cpp
#include <iostream>
#include <string>
#include <conio>
#include <vector>

using namespace std;
//Note that we can replace the two commented lines with
//the existing lines. In this case still it is possible
//to keep the by reference call for the vector initials.
//We may also change it to call by value which is more in
//tune with the return option used in this function.
void INITIALS(string&firstN, string& middleN,
//vector<char> INITIALS(string&firstN, string& middleN,
string& lastN, vector <char>& initials)
{
   initials.push_back(firstN[0]);
   initials.push_back('.');
   initials.push_back(middleN[0]);
   initials.push_back('.');
   initials.push_back(lastN[0]);
   initials.push_back('.');
//   return initials;
}

int main(void)

{  string First, Middle, Last;
   vector <char> initials;
   cout <<"Enter your complete name, First Middle Last:"
        << endl;
   cin >> First >> Middle >> Last;
   cout <<"First Name: " <<First<<"\nMiddle: "
   <<Middle<<"\nLast: "<<Last << endl;
   INITIALS(First,Middle,Last,initials);
   int i = 0;
   while(i < initials.size())
   {
      cout << initials[i];
      i = i+1;
   }
   cout << endl;
   getch();
   return 0;
}

