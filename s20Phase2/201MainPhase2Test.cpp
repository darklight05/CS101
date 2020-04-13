#include <iostream>
using namespace std;
#include "RBTree.cpp"

void printErrors(string errors, int numOfErrors){
	if(numOfErrors < 5){
		cout << errors << " passed " << endl;
	}else if(numOfErrors < 100){
		cout << errors << " caused " << numOfErrors << " of errors ADD+1" << endl;
		cout << errors << " caused " << numOfErrors << " of errors ADD+1" << endl;
		cout << errors << " caused " << numOfErrors << " of errors ADD+1" << endl;
	}else if (numOfErrors < 1000){
		cout << errors << " caused " << numOfErrors << " of errors ADD+1" << endl;
		cout << errors << " caused " << numOfErrors << " of errors ADD+1" << endl;
	}else if (numOfErrors < 10000){
		cout << errors << " caused " << numOfErrors << " of errors ADD+1" << endl;
	}else{
		cout << errors << " caused " << numOfErrors << " of errors" << endl;
	}
}


int main(){
	string K[10] = {"A","B","C","D","E","F","H","I","J","K"};
	int V[10] = {10,9,8,7,6,5,4,3,2,1};
	
	RBTree<string,int> T1, T2(K,V,10);
	T2.postorder();
	//A C B E H F J K I D
	
	for(int i=0; i<10; i++) T1.insert(K[i],V[i]);
	// T1 and T2 should be identical trees
	
	T1.insert("AA",11);
	T1.insert("AB",12);
	T1.insert("AC",13);
	cout << *(T1.search("AB")) << endl;
	// Should output 12
	
	cout << T1.rank("H") << endl;
	//Should output 10
	
	cout << T1.select(3) << endl;
	//Should output AB 
	
	T1.preorder();
	//Should output D B AA A AC AB C I F E H K J
	
	T1.inorder();
	//Should output	A AA AB AC B C D E F H I J K
	
	cout << T1.remove("HA") << endl;
	//Should output 0
	
	cout << T1.remove("AA") << endl;
	//Should output 1
	
	cout <<T1.rank("J") << endl;
	//Should output 11
	
	T1.inorder();
	//Should output	A AB AC B C D E F H I J K
	
//	RBTree<string,int> L, R;
//	T1.split("G", L, R);
//	cout << R.rank("K") << endl;
	// Should output 4
	
	int rankError = 0;
	int selectError = 0;
	int searchError = 0;
    RBTree<int,int> X;
	for (int i=100000;i>=0;i--) X.insert(i,100000-i);
	for (int i=1;i<100000;i++) {
		// cout << i+1 << " is i+1" << endl;
		// cout << X.rank(i) << " is rank" << endl;
		if(X.rank(i) != i+1) rankError++; //cout << "Rank error before delete" << endl;
		if(X.select(i) != i-1) selectError++; //cout << "Select error before delete" << endl;
		if(*(X.search(i)) != 100000-i) searchError++;//cout << "Search error before delete" << endl;
	}
	printErrors("Rank before delete",rankError);
	printErrors("Select before delete",selectError);
	printErrors("Search before delete",searchError);
	//cout << "Rank error is " << rankError << endl;
	//cout << "Select error is " << selectError << endl;
	//cout << "search error is " << searchError << endl;
	rankError=0;
	selectError=0;
	searchError=0;
	for (int i=0;i<100000;i+=13) X.remove(i);
	for (int i=1;i<100000-100000/13;i++){
		if (i%13) {
			if(X.rank(i) != i-i/13) rankError++; //cout << "Rank error after delete " << X.rank(i) << " should be " << i << " - " << i-i/13 << endl;
			if(*(X.search(i)) != 100000-i) searchError++;// cout << "Search error after delete" << endl;
		}
			int part1Answer = i / 13;
			int answer = i+(i+(i+(i+(i+(i + i / 13)/13)/13)/13)/13)/13;
			if(X.select(i) != answer){				
				selectError++;
				cout << "i is " << i << " Select error after delete " << X.select(i)  << " should be " << part1Answer << " +++ " << answer << endl;
			}
	}
	printErrors("Rank after delete",rankError);
	printErrors("Select after delete",selectError);
	printErrors("Search after delete",searchError);
	//cout << "Rank error is " << rankError << endl;
	//cout << "Select error is " << selectError << endl;
	//cout << "search error is " << searchError << endl;
	//Should be no output and should take seconds, not minutes
	cout << "Finished without failing" << endl << endl;
	return 0;
}
