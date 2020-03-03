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

	cout << "inorder "; T2.inorder(); cout << endl;
	cout << "postorder "; T2.postorder(); cout << endl;
	cout << "preorder "; T2.preorder(); cout << endl;

	cout << "Search of 12 = " << *(T2.search(12)) << endl;
	
	return 0;
}
