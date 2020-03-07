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
	int rankError = 0;
	int selectError = 0;
	int searchError = 0;
    RBTree<int,int> X;
    RBTree<int,int> Y;
    RBTree<int,int> Z;
	for (int i=100000;i>30000;i--) X.insert(i,100000-i);
	for (int i=29999;i>=0;i--) X.insert(i,100000-i);
	X.split(30000,Y,Z);
	for (int i=1;i<30500;i++) {
		if(i < 30000){
			if(Y.rank(i) != i+1) rankError++; //cout << "Rank error before delete" << endl;
			if(Y.select(i) != i-1) selectError++; //cout << "Select error before delete" << endl;
			if(*(Y.search(i)) != 100000-i) searchError++;//cout << "Search error before delete" << endl;
		}
		else{
			if(Z.rank(i) != i-30000){	
				rankError++; 
				//cout << "Rank error, i is " << i << " answer should be " << Z.rank(i) << " which is " << i-30000+1 << endl;
			}
			if(i > 30000 && Z.select(i-30000) != i) {
				selectError++; 
				//cout << "Select error, i is " << i << " answer should be " << Z.select(i-30000) << " which is " << i << endl;
			}
			if(i > 30000 && *(Z.search(i)) != 100000-i){
				searchError++;
				//cout << "Search error, i is " << i << " answer should be " << Z.search(i) << " which is " << 100000-i << endl;
			}
		}
	}
	printErrors("Rank",rankError);
	printErrors("Select",selectError);
	printErrors("Search",searchError);
	//Should be no output and should take seconds, not minutes
	cout << "Finished without failing" << endl << endl;
	return 0;
}
