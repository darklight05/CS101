#include <iostream>
#include "CDA.cpp"

using namespace std;

int main()
{
   int size, i, e, sort;
   cout << "size = ";
   cin >> size;

   CDA<int> tester7(size);

   for(i=0; i<size; i++)
      tester7[i] = rand() % size;

   cout << "Array of size " << tester7.Length() << " is : " << endl;
   tester7.printIndices();

   cout << endl << "What value would you like to search for? ";
   cin >> e;
   cout << endl;

   cout << "The value " << e << " occurs at index " << tester7.Search(e) << endl;

   cout << endl << "(1) Insert or (2) Counting sort : ";
   cin >> sort;

   if(sort == 1)
      tester7.InsertionSort();
   else
      tester7.CountingSort(size);

   cout << "Ordered = ";
   if(tester7.Ordered() == 0)
      cout << "false" << endl;
   else
      cout << "true" << endl;

   cout << endl << "AFTER sorting, the array is :" << endl;
   tester7.printIndices();

   cout << endl << "What value would you like to search for? ";
   cin >> e;
   cout << endl;
   cout << "The search value is at the index : " << tester7.Search(e) << endl;


   return 0;
}
