#include "RBTree.cpp"
#include <iostream>

using namespace std;

int main()
{
   int num;
   RBTree<int, int> tester1;
   int i;
   for(i=0; i<10; i++)
   {
      cout << "Inserting key #" << i << endl;
      tester1.insert(i, 10-i);
      tester1.preorder();
   }
   cout << endl << "Preorder:" << endl;
   tester1.preorder();
   cout << endl << "In order:" << endl;
   tester1.inorder();
   cout << endl << "Postorder:" << endl;
   tester1.postorder();

   cout << endl;
   cin >> num;
   cout << "rank of " << num << "= " << tester1.rank(num) << endl;

   return 0;
}
