//In this program, a rand char vec of even size is generated
//then another  vector, half the size of original vector
//is generated. The members of this vector are the sums of
//members which lie on each other as a result of folding the
//vector in half and on itself.That is, members 0,5 and 1,4
//and 2,3 for a six member vector

#include <iostream> // Needed for cin and cout
#include <stdlib>  // Needed for rand()
#include <vector>   // Needed to define the class
#include <conio>
using namespace std;

int main(void)
{  cout << "Size of random array (must be even and >= 2): ";
   int N; cin >> N;
   if (N%2 != 0 || N < 2)
   {  cout << "You must input an EVEN number >= 2. Try again.\n";
      getch();
      return 1;
   }
   
   vector<char> a(N);
   cout << "First vector: ";
   for (int i = 0; i < a.size(); i = i + 1)
   {  a[i] = rand()%10 + 65;
      cout << a[i] << " ";
   }
   cout << endl;
   
   cout << "Second vector: ";
   vector<char> b(N/2);
   for (int i = 0; i < b.size(); i = i + 1)
   {  b[i] = a[i] + a[N - i - 1];
      cout << b[i] << " ";
   }
   cout << endl;
   getch();
   return 0;
} // End of main()
