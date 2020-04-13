#include <iostream>
#include "RBTree.cpp"
using namespace std;

int main(){
    string K[3] = {"Taylor","Rachel","Caelis"};
    string V[3] = {"Eckenrode","Hoge","Wendel"};

    RBTree<string, string> T1(K, V, 3);

    cout << "I have only loved " << T1.size() << " girls, last names: ";
    for (int i = 0; i < 3; i++){
        cout << *(T1.search(K[i])) << " ";
    }
    cout << ", but i realized it too late." << endl;

    cout << "Always too slow on the jump" << endl;

    T1.rank("Taylor");

    cout << *(T1.successor("Rachel")) << ", she gave me too many chances." << endl;
    cout << *(T1.predecessor("Taylor")) << ", I just let her slip through the cracks." << endl;
    cout << T1.select(1) << ", I was never man enough to fight for her." << endl;
    cout << "just a couple ones that my heart lacks" << endl;
   

    return 0;
}