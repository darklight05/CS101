#include <iostream>
#include "CDA.cpp"

using namespace std;

int main()
{
   int size, i, sort;
   cout << "size = ";
   cin >> size;

   CDA<int> tester9(size);

   tester9.AddFront(5);

   CDA<int> tester10(tester9);

   return 0;
}
