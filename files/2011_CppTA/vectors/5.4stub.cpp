//File 5.4stub.cpp
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void sort(vector<int>& a){}

int main(void)
{  cout << "Input the minimum and maximum random int: ";
   int minRange, maxRange;
   cin >> minRange >> maxRange;
   
   cout << "Input the length of the vector: ";
   int vectorLength;
   cin >> vectorLength;
   
   vector<int> unsorted(vectorLength);
   cout << " Vector beforehand: \t";
   for (int i = 0; i < vectorLength; i = i + 1)
   {  unsorted[i] = minRange + rand()%(maxRange - minRange + 1); 
      cout << unsorted[i] << " ";
   }
   cout << "\n";
  
   sort(unsorted);
  
   cout << " Vector afterhand: \t";
   for (int i = 0; i < unsorted.size(); i = i + 1)
   {  cout << unsorted[i] << " ";
   }
   cout << "\n";
   return 0;
}
