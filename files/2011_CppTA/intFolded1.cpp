//Write a main function which forces the user to enter
//an even number >= 2. If the entry is invalid, the
//program should terminate itself.
//If the entry is valid, your main function should call
//a function called original vector() which takes the
//value of user entered even number N and produce a random
//vector of that size with elements between -10 and 10.
//The random vector should be returned to main() with the
//name original.
//A second function named modified(), then should be called.
//This function should take the original vector and N both
//by reference, add the first and last elemts of original,
//then second and next to last, ...etc and push_back these
//summations one by one into a new vector. Your second function
//should not return anything to main, but should print the
//new vector.
#include <iostream> // Needed for cin and cout
#include <stdlib>  // Needed for rand()
#include <vector>   // Needed to define the vector class
#include <conio>
using namespace std;

vector<int>  originalVector(int N );
void modified(vector<int>& firstVector,int& N);

int main(void)
{
   cout << "Size of random array (must be even and >= 2): ";
   int N; cin >> N;
   if (N%2 != 0 || N < 2)
   {  cout << "You must input an EVEN number >= 2. Try again.\n";
      getch();
      return 1;
   }
   else
   {
      vector <int> original = originalVector(N);
      modified(original, N);
   }
   getch();
   return 0;
}   
   
vector<int> originalVector(int N)
{
   vector<int> a(N);
   cout << "First vector: ";
   for (int i = 0; i < a.size() ; i = i + 1)  //Gives a warning for comparison of signed and unsigned values.
   {  a[i] = rand()%21 - 10;
      cout << a[i] << " ";
   }
   cout << endl;
   return a;
}

void modified(vector<int>& firstVector ,int& N)
{
   vector<int> b;
   for (int i = 0; i < N-i-1; i = i + 1)
   {  int c = firstVector[i] + firstVector[N - i - 1];
      b.push_back(c);
   }
   cout << endl << "The modified vector is:" << endl;
   for (unsigned int j=0; j<b.size(); j++)     //Does not give a comparison warning of signed and unsigned.
   {
      cout << b[j] << " ";
   }
   cout << endl;
   return ;
} // End of main()
