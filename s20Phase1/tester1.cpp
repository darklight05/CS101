
#include <iostream>
#include "CDA.cpp"

using namespace std;

int main()
{

   CDA<int> tester1;
   tester1.AddFront(5);
   tester1.AddFront(6);
   tester1.AddFront(7);
   tester1.AddFront(8);
   tester1.AddFront(0);
   tester1.AddFront(9);
   cout << "The size is " << tester1.Length();
   cout << " and the capacity is " << tester1.Capacity() << endl << endl;
   tester1.Clear();
   cout << "The size is " << tester1.Length();
   cout << " and the capacity is " << tester1.Capacity() << endl << endl;

   cout << "ADDING 4 TO FRONT" << endl;
   tester1.AddFront(4);
   
   cout << "The new size is " << tester1.Length();
   cout << " and the new capacity is " << tester1.Capacity() << endl;
   cout << "tester1[0] returns : " << tester1[0] << endl << endl;

   cout << "ADDING 10 TO END" << endl;
   tester1.AddEnd(10);

   cout << "The new size is " << tester1.Length();
   cout << " and the new capacity is " << tester1.Capacity() << endl;
   cout << "tester1[0] returns : " << tester1[0] << endl;
   cout << "tester1[1] returns : " << tester1[1] << endl << endl;

   cout << "ADDING 6 TO FRONT" << endl;
   tester1.AddFront(6);
   cout << "The new size is " << tester1.Length();
   cout << " and the new capacity is " << tester1.Capacity() << endl;
   cout << "ARRAY ORDERED CHECK : " << tester1.Ordered() << endl;
   cout << "tester1[0] returns : " << tester1[0] << endl;
   cout << "tester1[1] returns : " << tester1[1] << endl;
   cout << "tester1[2] returns : " << tester1[2] << endl << endl;

   cout << "ADDING 156 TO END" << endl;
   tester1.AddEnd(156);
   cout << "The new size is " << tester1.Length();
   cout << " and the new capacity is " << tester1.Capacity() << endl;
   cout << "tester1[0] returns : " << tester1[0] << endl;
   cout << "tester1[1] returns : " << tester1[1] << endl;
   cout << "tester1[2] returns : " << tester1[2] << endl;
   cout << "tester1[3] returns : " << tester1[3] << endl << endl;

   cout << "ADDING 7 TO FRONT" << endl;
   tester1.AddFront(7);

   cout << "The new size is " << tester1.Length();
   cout << " and the new capacity is " << tester1.Capacity() << endl;
   cout << "tester1[0] returns : " << tester1[0] << endl;
   cout << "tester1[1] returns : " << tester1[1] << endl;
   cout << "tester1[2] returns : " << tester1[2] << endl;
   cout << "tester1[3] returns : " << tester1[3] << endl;
   cout << "tester1[4] returns : " << tester1[4] << endl << endl;

   cout << "ADDING -4 TO FRONT" << endl;
   tester1.AddFront(-4);

   cout << "The new size is " << tester1.Length();
   cout << " and the new capacity is " << tester1.Capacity() << endl;
   cout << "tester1[0] returns : " << tester1[0] << endl;
   cout << "tester1[1] returns : " << tester1[1] << endl;
   cout << "tester1[2] returns : " << tester1[2] << endl;
   cout << "tester1[3] returns : " << tester1[3] << endl;
   cout << "tester1[4] returns : " << tester1[4] << endl;
   cout << "tester1[5] returns : " << tester1[5] << endl << endl;
   
   cout << "DELETING END" << endl;
   tester1.DelEnd();

   cout << "The new size is " << tester1.Length();
   cout << " and the new capacity is " << tester1.Capacity() << endl;
   cout << "tester1[0] returns : " << tester1[0] << endl;
   cout << "tester1[1] returns : " << tester1[1] << endl;
   cout << "tester1[2] returns : " << tester1[2] << endl;
   cout << "tester1[3] returns : " << tester1[3] << endl;
   cout << "tester1[4] returns : " << tester1[4] << endl << endl;

   cout << "DELETING FRONT" << endl;
   tester1.DelFront();

   cout << "The new size is " << tester1.Length();
   cout << " and the new capacity is " << tester1.Capacity() << endl;
   cout << "tester1[0] returns : " << tester1[0] << endl;
   cout << "tester1[1] returns : " << tester1[1] << endl;
   cout << "tester1[2] returns : " << tester1[2] << endl;
   cout << "tester1[3] returns : " << tester1[3] << endl << endl;

   cout << "DELETING END" << endl;
   tester1.DelEnd();

   cout << "The new size is " << tester1.Length();
   cout << " and the new capacity is " << tester1.Capacity() << endl;
   cout << "tester1[0] returns : " << tester1[0] << endl;
   cout << "tester1[1] returns : " << tester1[1] << endl;
   cout << "tester1[2] returns : " << tester1[2] << endl << endl;
   
   cout << "DELETING END" << endl;
   tester1.DelEnd();

   cout << "The new size is " << tester1.Length();
   cout << " and the new capacity is " << tester1.Capacity() << endl;
   cout << "tester1[0] returns : " << tester1[0] << endl;
   cout << "tester1[1] returns : " << tester1[1] << endl << endl;
   
   cout << "DELETING FRONT" << endl;
   tester1.DelFront();

   cout << "The new size is " << tester1.Length();
   cout << " and the new capacity is " << tester1.Capacity() << endl;
   cout << "tester1[0] returns : " << tester1[0] << endl << endl;
   
   cout << "DELETING FRONT" << endl;
   tester1.DelFront();

   cout << "The new size is " << tester1.Length();
   cout << " and the new capacity is " << tester1.Capacity() << endl;
   return 0;
}

