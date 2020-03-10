#include <iostream>
#include "RBTree.cpp"
using namespace std;

int main(){
    // int K[11] = {0,1,2,3,4,5,6,7,8,9,10};
    // int V[11] = {10,9,8,7,6,5,4,3,2,1,0};
    string K[10] = {"A","B","C","D","E","F","G","H","I","K"};
	int V[10] = {10,9,8,7,6,5,4,3,2,1};
    RBTree<string, int> T1; 
    for(int i=0; i<10; i++) {
		T1.insert(K[i], V[i]);
	}

    T1.inorder();
    cout << endl;

    cout << "Rank at A = " << T1.rank("A") << endl;
    cout << "Rank at B = " << T1.rank("B") << endl;
    cout << "Rank at C = " << T1.rank("C") << endl;
    cout << "Rank at D = " << T1.rank("D") << endl;
    cout << "Rank at E = " << T1.rank("E") << endl;
    cout << "Rank at F = " << T1.rank("F") << endl;
    cout << "Rank at G = " << T1.rank("G") << endl;
    cout << "Rank at H = " << T1.rank("H") << endl;
    cout << "Rank at I = " << T1.rank("I") << endl;
    cout << "Rank at K = " << T1.rank("K") << endl;
    //cout << "Rank at 10 = " << T1.rank(10) << endl;
    return 0;
}