#include <iostream>
#include "CDA.cpp"

using namespace std;

int main()
{
   int i;
   int size = 12;
   CDA<int> tester3(size);

   for(i=0; i<size; i++)
   {
      tester3[i] = size-1-i;
   } 

   tester3.AddFront(8);
   size++;

   tester3.AddEnd(8);
   size++;
   cout << "BEFORE:" << endl;
   for(i=0; i<size-1; i++)
   {
      cout << tester3[i] << ", ";
   }
   cout << tester3[size-1] << endl << endl;

   tester3.InsertionSort();

   cout << "AFTER:" << endl;
   for(i=0; i<size-1; i++)
   {
      cout << tester3[i] << ", ";
   }
   cout << tester3[size-1] << endl << endl;

   return 0;
}

