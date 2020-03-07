#include "RBTree.cpp"
#include <iostream>

using namespace std;

int main()
{

   int i, size;
   size = 10;

   int k[size], V[size];
   for(i=0; i<size; i++)
   {
      k[i] = i+1;
      V[i] = i+1;
   } 
   RBTree <int, int> tester4(k, V, size);
   cout << endl << "Postorder:" << endl;
   tester4.postorder();
   cout << endl << "In order:" << endl;
   tester4.inorder();
   cout << endl << "Preorder:" << endl;
   tester4.preorder();

   //cout << "Get Value in Key : ";
   //cin >> num;

   //cout << endl << "Search returns " << num << " is " << *(tester4.search(num)) << endl;

   cout << endl << "START REMOVING:" << endl;
   cout << "REMOVING 1" << endl;
   int result = tester4.remove(1);
   cout << "Removed Status : " << result << endl;
   tester4.preorder();

   cout << endl << "REMOVING 2" << endl;
   result = tester4.remove(2);
   cout << "Removed Status : " << result << endl;
   tester4.preorder();

   cout << endl << "REMOVING 3" << endl;
   result = tester4.remove(3);
   cout << "Removed Status : " << result << endl;
   tester4.preorder();

   return 0;
}
