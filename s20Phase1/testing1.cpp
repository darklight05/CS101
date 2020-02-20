#include <iostream>
#include <stdlib.h>
using namespace std;
//#include "CDA.cpp"
#include "cdatest.cpp"

int main(){
    CDA<int> A;
    for (int i = 0; i < 10; i++) A.AddEnd(rand() % 100);
    // 41 67 34 0 69 24 78 58 62 64
    for (int i = 0; i < A.Length(); i++) cout << A[i] << " "; cout << endl;
    cout << "Search for 67 is at index " << A.Search(67) << endl;
    // Search(67) is at index 1;
    A.AddFront(3);
    for (int i = 0; i < A.Length(); i++) cout << A[i] << " "; cout << endl;
    // 3 41 67 34 0 69 24 78 58 62 64
    A.AddFront(24); A.AddFront(34);
    for (int i = 0; i < A.Length(); i++) cout << A[i] << " "; cout << endl;
    // 24 3 41 67 34 34 0 69 24 78 58 62 64
    cout << "count sorting" << endl;
    A.CountingSort(100);
    //A.QuickSort();
    cout << "post sort ->" << endl;
    for (int i = 0; i < A.Length(); i++) cout << A[i] << " "; cout << endl;
    // 0 3 24 24 34 34 41 58 62 64 67 69 78
    cout << "Kth smallest at 3 is " << A.Select(3) << endl;
    // Kth smallest at 3 is 24
    A.DelEnd(); A.DelFront(); 
    for (int i = 0; i < A.Length(); i++) cout << A[i] << " "; cout << endl;
    // 3 24 24 34 41 58 62 64 67 69
    cout << "end testing of array A" << endl;
    cout << endl;
    CDA<int> B;
    B = A;
    cout << "Array B after equal operator" << endl;
    for (int i = 0; i < A.Length(); i++) cout << B[i] << " "; cout << endl;
    // 3 24 34 41 58 62 64 67 69
    B.DelEnd(); B.DelFront();
    for (int i = 0; i < B.Length(); i++) cout << B[i] << " "; cout << endl;
    cout << "End testing of array B" << endl;
    cout << endl;
    CDA<int> C(16);
    for (int i = 0; i < 16; i++) C[i] = rand() % 100;
    for (int i = 0; i < C.Length(); i++) cout << C[i] << " "; cout << endl;
    // 5 45 81 27 61 91 95 42 27 36 91 4 2 53 92 82
    cout << "select of 3 is " << C.Select(3) << endl;
    cout << "search of 63 is " << C.Search(59) << endl;
    // select is 5
    // search is 5
    cout << "Quick Sorting..." << endl;
    C.QuickSort();
    for (int i = 0; i < C.Length(); i++) cout << C[i] << " "; cout << endl;
    // 2 4 5 27 27 36 42 45 53 61 81 82 91 91 92 95
    C.Clear();
    C.AddEnd(1);
    for (int i = 0; i < C.Length(); i++) cout << C[i] << " "; cout << endl;
    // 1
    cout << "end testing of array C" << endl << endl;
    cout << endl; 
    CDA<int> D(20000);
    //for (int i = 0; i < 5000000; i++) D[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
    for (int i = 0; i < 20000; i++) D[i] = rand() % 2001;
    //for (int i = 0; i < 5000000; i++) cout << D[i] << " "; cout << endl;
    //D.CountingSort(2001);
    cout << "Insertion Sorting..." << endl;
    D.InsertionSort();
    cout << "D array setOrdered is " << D.SetOrdered() << endl;
    // setordered should be 1
    cout << "end testing array D" << endl << endl;
    CDA<int> E(250000);
    for (int i = 0; i < 50000; i++) E[i] = rand() % 2001;
    cout << "Count Sorting..." << endl;
    E.CountingSort(2001);
    cout << "E Order is " << E.Ordered() << endl;
    cout << "end testing of array E" << endl << endl;
    CDA<float> F(50000);
    for (int i = 0; i < 50000; i++) F[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
    cout << "F setOrdered is " << F.SetOrdered() << endl;
    cout << "Select of 250 is " << F.Select(250) << endl;
    cout << "Search of 1009 is " << F.Search(1009) << endl;
    cout << "Quick Sorting..." << endl;
    F.QuickSort();
    cout << "F Order is " << F.Ordered() << endl;

    return 0;
}