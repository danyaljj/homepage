//File 5.6stub.cpp
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void noRepeats(vector<int>& a){}

int main(void)
{  cout << "Input the minimum and maximum random int: ";
   int minRange, maxRange;
   cin >> minRange >> maxRange;
   
   cout << "Input the length of the vector: ";
   int vectorLength;
   cin >> vectorLength;
   
   vector<int> hasRepeats(vectorLength);
   cout << " Vector beforehand: \t";
   for (int i = 0; i < vectorLength; i = i + 1)
   {  hasRepeats[i] = minRange + rand()%(maxRange - minRange + 1); 
      cout << hasRepeats[i] << " ";
   }
   cout << "\n";
  
   noRepeats(hasRepeats);
  
   cout << " Vector afterhand: \t";
   for (int i = 0; i < hasRepeats.size(); i = i + 1)
   {  cout << hasRepeats[i] << " ";
   }
   cout << "\n";
   return 0;
}
