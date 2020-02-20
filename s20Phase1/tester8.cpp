#include <iostream>
#include "CDA.cpp"

using namespace std;

int main()
{
   int size, i, sort;
   cout << "size = ";
   cin >> size;

   CDA<int> tester8(size);

   for(i=0; i<size; i++)
      tester8[i] = rand() % size;

   cout << "Array of size " << tester8.Length() << " is : " << endl;
   tester8.print();

   cout << endl << "(1) Insert or (2) Counting sort or (3) QuickSort : ";
   cin >> sort;

   if(sort == 1)
      tester8.InsertionSort();
   else if(sort == 2)
      tester8.CountingSort(size);
   else
      tester8.QuickSort();

   cout << "Ordered = ";
   if(tester8.Ordered() == 0)
      cout << "false" << endl;
   else
      cout << "true" << endl;

   cout << endl << "AFTER sorting, the array is :" << endl;
   tester8.print();

   return 0;
}
