#include <iostream>
#include <stdlib.h>
using namespace std;
#include "CDA.cpp"
//#include "cdatest.cpp"

int main() {
    CDA<int> C(16);
    for (int i = 0; i < 16; i++) C[i] = rand() % 100;
    for (int i = 0; i < C.Length(); i++) cout << C[i] << " "; cout << endl;
    // 5 45 81 27 61 91 95 42 27 36 91 4 2 53 92 82
    cout << "select of 3 is " << C.Select(3) << endl;
    cout << "search of 83 is " << C.Search(83) << endl;

    return 0;
}