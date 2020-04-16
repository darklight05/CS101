#include <iostream>

using namespace std;

template <typename keytype, typename valuetype>
class BHeap {
    private:
        struct Node{
            keytype key;
            valuetype value;
            int degree;
            Node *parent; *child; *sibling;
            Node() {
                this->parent = NULL;
                this->sibling = NULL;
                this->child = NULL;
                this->degree = 0;
            }
        };

        Node *Tnil;
        Node *Troot;    //roots of each binomial trees
        Node *Broot;    //root of the binomial heap
        BHeap *heapArray; 

        public:
            BHeap(){
                Tnil = new Node;
                Troot = Tnil;
                //Broot = Tnil;
                heapArray = new *BHeap[1];
                heapArray[0] = Tnil;
            }

            BHeap(keytype k[], valuetype v[], int s){
                Tnil = new Node;
                Troot = Tnil;
                Broot = Tnil;
            }
};