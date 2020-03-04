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

    for (int i=0; i<11; i++){
        cout << "Rank of " << i << " = " << T1.rank(i) << endl;
    }
    return 0;
}