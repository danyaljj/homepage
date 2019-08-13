//File 5.5stub.cpp
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> getPrimes(const int NPrimes){}

int main(void)
{  cout << "Input the number of primes to find: ";
   int NPrimes;
   cin >> NPrimes;
   
   vector<int> primes = getPrimes(NPrimes); //Get the primes
   cout << "The first " <<  primes.size() << " prime numbers: ";

   for (int i = 0; i < primes.size(); i = i + 1)
   {  cout << primes[i] << " ";
   }
   cout << "\n";
   return 0;
}
