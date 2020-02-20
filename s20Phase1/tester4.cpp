#include <iostream>
#include "CDA.cpp"

using namespace std;

int main()
{
   int i;
   int size = 12;
   CDA<int> tester4(size);

   cout << "size = " << tester4.Length() << endl;
   cout << "cap = " << tester4.Capacity() << endl;

   for (i=0; i<size; i++)
   {
      tester4[i] = i;
   }


   cout << "THE MAIN FILE ARRAY = ";
   for (i=0; i<size-1; i++)
   {
      cout << tester4[i] << ", ";
   }
   cout << tester4[size-1] << endl << endl;

   for (int i = 0; i < tester4.Length(); i++) cout << tester4[i] << " "; cout << endl;

   return 0;
}

