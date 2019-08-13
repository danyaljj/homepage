//Rewrite this same program without creating a new vector
//b. Simply, as soon as a perfect square is encountered,
//push_back its index into vector ind, eliminate the
//perfect square term in vector a (using pop_front) and
//continue the procedure until all indices of perfect
//squares are identified.
#include <iostream>// Needed for cin and cout
#include <stdlib>  // Needed for rand()
#include <vector>  // Needed to define the vector class
                   // Is also needed for namespace in Borland
#include <time>    // Needed for time()
#include <math>    // Needed for sqrt()
#include <conio>   //Needed for keeping DOS window in Borland
using namespace std;

vector<int> reduce(vector<int>& a) //Call by reference
{  vector<int> ind, b; //Two int vectors are declared
   for (int i = 0; i < a.size(); i = i + 1)
   {  int sqr = static_cast<int>(sqrt(a[i])); //func sqrt()
      if (sqr*sqr == a[i]) ind.push_back(i);  //populates
      //ind with indices of sqr elements from the left
      else b.push_back(a[i]);
      //populates b with nonsqr elems
   }
   a = b; //Changes the value of referenced "a" vector
   return ind;  //Returns the vector<int> ind()
} 

int main(void)
{  cout << "Size of vector (must be >= 1): ";
   int N; cin >> N;
   srand(time(NULL));
   vector<int> a(N);

   cout << "Original vector is: ";
   for (int i = 0; i < a.size(); i = i + 1)
   {  a[i] = rand()%10 + 1;
      cout << a[i] << " ";
   }
   cout << endl;

   vector<int> ind = reduce(a); // <---- User defined function
   
   cout << "Indices of the square elements in the\n"
        << "original vector are: ";
   for (int i = 0; i < ind.size(); i = i + 1)
      cout << ind[i] << " ";
   cout << endl;

   cout << "The original vector elements that were\n" 
        << "not perfect squares are: ";
   for (int i = 0; i < a.size(); i = i + 1)
      cout << a[i] << " ";
   cout << endl;
   getch();
   return 0;
}
