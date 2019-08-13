//File 5.2stub.cpp
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void minMax\
(const vector<int>& c, int& min, int& max)
{  //Why were min and max given as "reference parameters"?
   //Answer the question and insert your code after this line.
}

int main(void)
{  int vectorLength = 8;

   vector<int> a(vectorLength);
   cout << " a: ";
   for (int i = 0; i < vectorLength; i = i + 1)
   {  a[i] = rand(); 
      cout << "\t" << a[i];
   }
   cout << "\n";
   
   int minimum, maximum;
   minMax(a, minimum, maximum);
   
   cout << "The minimum array element is: " << minimum << "\n";
   cout << "The maximum array element is: " << maximum << "\n";
   
   return 0;
}
