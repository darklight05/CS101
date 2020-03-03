#include <iostream>
#include "RBTree.cpp"
using namespace std;

int main(){
    RBTree<int,int> X;
        for (int i=1;i<100000;i++) X.insert(i,i);
        for (int i=1;i<100000;i++) {
            //if(X.rank(i) != i) cout << "Rank error" << endl;
            //if(X.select(i) != i) cout << "Select error" << endl;
            if(*(X.search(i)) != i) cout << "Search error" << endl;
        }  
        //Should be no output and should take seconds, not minutes
        return 0;
}