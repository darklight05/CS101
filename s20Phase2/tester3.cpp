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

   RBTree<int, int> tester3(a, v, n);

/*
   RBTree<int, int> tester3;
   
   for(i=0; i<size; i++)
   {
      tester3.insert(a[i], v[i]);
      tester3.preorder();
   }
*/
   cout << endl << endl << endl;
   cout << "IN ORDER : " << endl;
   tester3.inorder();

   cout << endl << "PRE ORDER : " << endl;
   tester3.preorder();


   while(breaker != 0)
   {
      cout << "Get rank of : ";
      cin >> num;
      breaker = tester3.rank(num);
      cout << "Rank of " << num << " = " << breaker << endl << endl;
   }

 
   return 0;
}
