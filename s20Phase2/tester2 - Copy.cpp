#include "RBTree.cpp"
#include <iostream>

using namespace std;

int main()
{
   int i, num; 
   int k[10], V[10];
   for(i=0; i<10; i++)
   {
      k[i] = i+1;
      V[i] = i+1;
   } 
   RBTree <int, int> tester2(k, V, 10);
   cout << endl << "Preorder:" << endl;
   tester2.preorder();
   cout << endl << "In order:" << endl;
   tester2.inorder();
   cout << endl << "Postorder:" << endl;
   tester2.postorder();

   cout << "Get Value in Key : ";
   cin >> num;

   cout << endl << "Search returns " << num << " is = " << *(tester2.search(num)) << endl;

   return 0;
}
