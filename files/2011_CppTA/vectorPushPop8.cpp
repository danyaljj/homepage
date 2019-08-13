//Exam2, Question 2, Winter 2003
//This program finds all the numbers divisible by 2 & 3
//but not 5 less than a given int.
//It then divides the set in half and prints them in
//ascending and descending order respectively. If the
//set population is odd, the last one is dropped.

#include <iostream>
#include <vector>
#include <conio>

using namespace std;

int main(void)
{  int N;
   cout << "Magnitude of positive int to test: ";
   cin >> N;
   if (N < 1)
   {
      cout << "You must enter a positive number. Try again!\n";
      return 1;
   }
   
   cout << "Will find the positive ints <= " << N
        << " divisible by 2 and 3, but not 5\n";
   
   vector<int> a, b;
   
   // Enter your solution below. You may not create
   //new vectors.
   for (int i = 1; i <= N; i = i + 1)
      if (i%2 == 0 && i%3 == 0 && i%5) //true only when
         a.push_back(i);       //i%5 !=0, which is true
       //populates a          //T&&T&&T==> T
   cout << "The vector called a is: ";
   for (int i = 0; i < a.size(); i = i + 1)
      cout << a[i] << " ";
   cout << endl;

   if (a.size()%2)
   {
      a.pop_back(); //eliminates elements one by one from the end
      cout << "The vector called a had an odd length, so the last element was trimmed.\n";
   }
   
   int oldSize = a.size();
   int newSize = oldSize/2;
   for (int i = 0; i < newSize; i = i + 1)
   {
      b.push_back(a[oldSize - 1 - i]);//pushing last elements
      a.pop_back();   //into b and eliminating them from a
   }
   
   cout << "The revised vector called a is: ";
   for (int i = 0; i < a.size(); i = i + 1)
      cout << a[i] << " ";
   cout << endl;

   cout << "The vector called b is: ";
   for (int i = 0; i < b.size(); i = i + 1)
      cout << b[i] << " ";
   cout << endl;

   // Enter your solution above.
   getch();
   return 0;
}
