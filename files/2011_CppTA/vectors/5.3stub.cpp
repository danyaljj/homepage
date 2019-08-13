//File 5.3stub.cpp
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> nothingNegative(const vector<int>& a)
{  //Why can this program, when compiled with just the function stub,
   //go into what looks like an infinite loop?
   //Answer the question and insert your code after this line.
}

int main(void)
{  int vectorLength = 10;

   vector<int> bothSigns(vectorLength);
   cout << " Input vector: ";
   for (int i = 0; i < vectorLength; i = i + 1)
   {  bothSigns[i] = rand()%201 - 100;
     cout << "\t" <<  bothSigns[i];
   }
   cout << "\n";
   
   vector<int> noNegs = nothingNegative(bothSigns);
   
   cout << " Output vector: ";
   cout << "1111   " << noNegs.size();
   for (int i = 0; i < noNegs.size(); i = i + 1)
   { // cout << "\t" <<  noNegs[i];
   }
   cout << "\n";
   cout << "2222   " << noNegs.size();
   
   return 0;
}
