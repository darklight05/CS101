#include <iostream>
#include <bits/stdc++.h>
#include "RBTree.cpp"

using namespace std;

int main()
{
   int size = 200;

   int i, a[size], v[size], num, breaker;
   unsigned seed = 0;

   for(i=1; i<=size; i++)
   {
      a[i-1] = i;
      v[i-1] = 4;
   }

   int n = sizeof(a)/sizeof(a[0]);
   cout << n << endl;
   
   for(i=0; i<size; i++)
      cout << a[i] << " ";
   cout << endl;
   shuffle(a, a+n, default_random_engine(seed));

   for(i=0; i<size; i++)
      cout << a[i] << " ";
   cout << endl;

   RBTree<int, int> tester6(a, v, n);

   cout << endl << endl << endl;
   cout << "IN ORDER : " << endl;
   tester6.inorder();

   cout << endl << "PRE ORDER : " << endl;
   tester6.preorder();

   cout << endl << tester6.rank(200) << endl;

   while(breaker != 0)
   {
      cout << endl << "Delete what? ";
      cin >> num;
      breaker = tester6.remove(num);
      tester6.preorder();
      cout << endl;
      tester6.inorder();
   }
   breaker = 1;
   while(breaker != 0)
   {
      cout << endl << "Get rank of what? ";
      cin >> num;
      breaker = tester6.rank(num);
      cout << "Rank of " << num << " is " << breaker << endl;
   }

   return 0;
}
