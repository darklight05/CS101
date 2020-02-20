#include <iostream>
#include "CDA.cpp"

using namespace std;

int main()
{
   int k = 10;
   int size = 10;
   if(k>size)
      k = size-1;
   int i;
   CDA<int> tester2(size);

   cout << "The array size is " << tester2.Length() << " and the capacity is "
   << tester2.Capacity() << endl;

   cout << "ADD -1 AT FRONT" << endl;
   tester2.AddFront(-1);
   size++;
   cout << "The array size is " << tester2.Length() << " and the capacity is "
   << tester2.Capacity() << endl;

   for(i=size-1; i>0; i--)
   {
      tester2[i] = size-1-i;
   }
  
   cout << "tester2.Ordered() returns : " << tester2.Ordered() << " before SetOrdered" << endl; 
   if (tester2.SetOrdered() == 1)
   {
      cout << "Ordered == true" << endl;
   }
   else
   {
      cout << "Ordered == false " << endl;
   }

   cout << "tester2.Ordered() returns : " << tester2.Ordered() << " after SetOrdered" << endl << endl;
   cout << "ORDER BEFORE SEARCH" << endl;
   for(i=0; i<size; i++)
   {
      cout << "Pos " << i << " = " << tester2[i] << endl;
   }
   cout << endl;

   cout << "The (" << k << ")th smallest element is " << tester2.Select(k) << endl << endl;
   cout << "ORDER AFTER SEARCH" << endl;
   for(i=0; i<size; i++)
   {
      cout << "Pos " << i << " = " << tester2[i] << endl;
   }

   return 0;
}

