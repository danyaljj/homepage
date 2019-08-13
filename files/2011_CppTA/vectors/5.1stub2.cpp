//File 5.1stub.cpp
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

float innerProduct\
(const vector<float>& a, const vector<float>& b)
{  //Why did the function use the const qualifiers in the parameter list
   //and pass the vectors by reference?
}

int main(void)
{  int vectorLength = 10;

   vector<float> x(vectorLength);
   cout << " x: ";
   for (int i = 0; i < vectorLength; i = i + 1)
   {  x[i] = rand()%100; 
      cout << "\t" << x[i];
   }
   cout << "\n";
   
   vector<float> y(vectorLength);
   cout << " y: ";
   for (int i = 0; i < vectorLength; i = i + 1)
   {  y[i] = rand()%10; 
      cout << "\t" << y[i];
   }
   cout << "\n";
   
   cout << "Inner product is: " << innerProduct(x,y) << "\n";
   
   return 0;
}
