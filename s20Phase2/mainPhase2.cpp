#include <iostream>
#include "RBTree.cpp"
using namespace std;

int main(){
	// int K[11] = {0,1,2,3,4,5,6,7,8,9,10};
    // int V[11] = {10,9,8,7,6,5,4,3,2,1,0};
	string K[11] = {"a","b","c","d","e","f","g","h","i","j","l"};
	string V[11] = {"a","b","c","d","e","f","g","h","i","j","l"};

	cout << "T1, RBTree() test" << endl;
	RBTree<string, string> T1; 
	for(int i=0; i<11; i++) {
		T1.insert(K[i], V[i]);
	}
	RBTree<string, string> T2;
	T2 = T1;
	cout << "size is " << T1.size() << endl;
	cout << "inorder T1 "; T1.inorder();
	cout << "inorder T2 "; T2.inorder();
	//T1.remove(4);
	
	//T2.~RBTree();


	// cout << "inorder T1 "; T1.inorder();
	cout << "inorder T2 "; T2.inorder();
	//cout << "before deconstructor" << endl;
	//T2.~RBTree();
	//cout << "inorder T2 "; T2.inorder();
	//cout << "after deconstructor" << endl;
	//cout << "inorder T3 "; T3.inorder();
	// cout << "postorder "; T1.postorder();
	// cout << "preorder "; T1.preorder();
	// cout << "size is " << T1.size() << endl;

	// cout << "removing 0 is " << T1.remove(0) << endl;
	// cout << "Rank of 5 = " << T1.rank(5) << endl;
	// cout << "removing 1 is " << T1.remove(1) << endl;
	// cout << "inorder "; T1.inorder();
	// cout << "preorder "; T1.preorder();
	// cout << "postorder "; T1.postorder();
	// cout << "size is " << T1.size() << endl;
	
	// cout << "T2, RBTree(keytype K[], valuetype V[], int s) test" << endl;
	// RBTree<int, int> T2(K,V,11);

	// cout << "inorder "; T2.inorder();
	// cout << "postorder "; T2.postorder();
	// cout << "preorder "; T2.preorder();

	// cout << "Search of 9 = " << *(T2.search(9)) << endl;
	// cout << "Rank of 4 = " << T2.rank(4) << endl;
	// cout << "Select at pos(6) = " << T2.select(6) << endl;
	// cout << "Successor of 2 = " << *(T2.successor(2)) << endl; //should be 6
	// cout << "Predecessor of 4 = " << *(T2.predecessor(4)) << endl; //should be 4
	return 0;
}
