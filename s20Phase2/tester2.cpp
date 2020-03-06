#include <iostream>
#include "RBTree.cpp"
using namespace std;

int main(){
    string K[10] = {"A","B","C","D","E","F","G","H","I","K"};
	int V[10] = {10,9,8,7,6,5,4,3,2,1};
	
	RBTree<string,int> T1, T2(K,V,10);
	
	for(int i=0; i<10; i++) T1.insert(K[i],V[i]);
	// T1 and T2 should be identical trees
	
    T2.preorder();
	//Should output D B A C F E H G I K

	T2.inorder();
	//Should output	A B C D E F G H I K

	cout << *(T2.search("L")) << endl;
	// Should output 8

    cout << "Rank of C = " << T2.rank("C") << endl;
        return 0;
}