#include <iostream>
#include "RBTree.cpp"
using namespace std;

int main(){
    int K[11] = {0,1,2,3,4,5,6,7,8,9,10};
    int V[11] = {10,9,8,7,6,5,4,3,2,1,0};
    RBTree<int, int> T1; 
    for(int i=0; i<11; i++) {
		T1.insert(K[i], V[i]);
	}

    T1.inorder();
    cout << endl;

    cout << "Rank at 0 = " << T1.rank(0) << endl;
    cout << "Rank at 1 = " << T1.rank(1) << endl;
    cout << "Rank at 2 = " << T1.rank(2) << endl;
    cout << "Rank at 3 = " << T1.rank(3) << endl;
    cout << "Rank at 4 = " << T1.rank(4) << endl;
    cout << "Rank at 5 = " << T1.rank(5) << endl;
    cout << "Rank at 6 = " << T1.rank(6) << endl;
    cout << "Rank at 7 = " << T1.rank(7) << endl;
    cout << "Rank at 8 = " << T1.rank(8) << endl;
    cout << "Rank at 9 = " << T1.rank(9) << endl;
    cout << "Rank at 10 = " << T1.rank(10) << endl;
    return 0;
}