/*********************************************************************
Copyright (C) :    University of Michigan
Project:           ENG101/200 - Class example
File:              string3.cpp
Purpose:           Examine string member functions
Start Date:        2/19/01
*********************************************************************/
//File: string4.cpp
#include <iostream>
#include <string>
#include <conio.h>

//using namespace std;

int main(void)
{  string winner = "Bush";
   string loser = "Gore";
   cout << "The winner of the election was "
        << winner << endl;
   cout << "The loser of the election was " << loser
        << endl;
   string result = winner.substr(0,1) + loser.substr(1,3);
   cout << "The public thought it was all a big "
        << result << endl;
   getch();
   return 0;
}

