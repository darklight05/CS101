#include <iostream>
#include "RBTree.cpp"
using namespace std;

int main(){
	// int K[11] = {0,1,2,3,4,5,6,7,8,9,10};
    // int V[11] = {10,9,8,7,6,5,4,3,2,1,0};

    cout << "Testing predecessor" << endl;

    RBTree<int, int> T1;
    for (int i = 0; i < 1000000; i++){
        T1.insert(i, i);
    }
    // cout << *(T1.successor(10)) << endl;
    for (int i = 1; i < 1000000; i++){
        if (!(*(T1.predecessor(i)) < i)){
            cout << "this is false" << endl;
        }
    }
    cout << "predecessor test over" << endl;

    // for (int i = 0; i < 999999; i++){
    //     cout << i << endl;
    //     if (*(T1.successor(i)) != i+1){
    //         cout << "successor breaks" << endl;
    //     }
    // }
    cout << T1.select(1) << endl;
    cout << "successor of 999995 = " << *(T1.successor(999995)) << endl;
    return 0;
}
