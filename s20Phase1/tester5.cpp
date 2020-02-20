#include <iostream>
#include <cstdlib>
#include "CDA.cpp"

using namespace std;

int main()
{

   CDA<int> tester5;
   cout << "size = " << tester5.Length() << endl;
   cout << "Cap = " << tester5.Capacity() << endl << endl;
   cout << "ADDING 1 TO END" << endl;

   tester5.AddEnd(1);
   cout << "size = " << tester5.Length() << endl;
   cout << "Cap = " << tester5.Capacity() << endl << endl;

   cout << "pos 0 = " << tester5[0] << endl;

   cout << "ADDING 2 TO END" << endl;

   tester5.AddEnd(2);
   cout << "size = " << tester5.Length() << endl;
   cout << "Cap = " << tester5.Capacity() << endl << endl;

   cout << "pos 0 = " << tester5[0] << endl;
   cout << "pos 1 = " << tester5[1] << endl;

   cout << "ADDING 3 TO END" << endl;

   tester5.AddEnd(3);
   cout << "size = " << tester5.Length() << endl;
   cout << "Cap = " << tester5.Capacity() << endl << endl;

   cout << "pos 0 = " << tester5[0] << endl;
   cout << "pos 1 = " << tester5[1] << endl;
   cout << "pos 2 = " << tester5[2] << endl;


   return 0;
}
