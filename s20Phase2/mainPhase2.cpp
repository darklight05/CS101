#include <iostream>
#include "RBTree.cpp"
using namespace std;

int main(){
	int K[11] = {0,1,2,3,4,5,6,7,8,9,10};
    int V[11] = {10,9,8,7,6,5,4,3,2,1,0};

	cout << "T1, RBTree() test" << endl;
	RBTree<int, int> T1; 
	for(int i=0; i<11; i++) {
		T1.insert(K[i], V[i]);
	}
	cout << "inorder "; T1.inorder(); cout << endl;
	cout << "postorder "; T1.postorder(); cout << endl;
	cout << "preorder "; T1.preorder(); cout << endl;
	cout << "size is " << T1.size() << endl;
	
	cout << "T2, RBTree(keytype K[], valuetype V[], int s) test" << endl;
	RBTree<int, int> T2(K,V,11);

	cout << "inorder "; T2.inorder();
	cout << "postorder "; T2.postorder();
	cout << "preorder "; T2.preorder();

	cout << "Search of 1 = " << *(T2.search(1)) << endl;
	cout << "Rank of 4 = " << T2.rank(4) << endl;
	cout << "Select at pos(6) = " << T2.select(6) << endl;
	cout << "Successor of 2 = " << *(T2.successor(2)) << endl; //should be 6
	cout << "Predecessor of 4 = " << *(T2.predecessor(4)) << endl; //should be 4
	return 0;
}
