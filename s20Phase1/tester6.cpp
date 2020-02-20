#include <iostream>
#include "CDA.cpp"

using namespace std;

int main()
{
   int size, max, i;
   cout << "size = ";
   cin >> size;
   cout << "max number = ";
   cin >> max;

   CDA<int> tester6(size);

   for(i=0; i<size; i++)
   {
      tester6[i] = i%max;
   }
   cout << "Size = " << tester6.Length() << endl;
   cout << "Capacity = " << tester6.Capacity() << endl << endl;

   cout << "BEFORE:" << endl;
   tester6.print();

   tester6.CountingSort(max-1);
   
   cout << endl << "AFTER:" << endl;
   tester6.print();

   return 0;
}
