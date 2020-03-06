//successor and predecessor broken again
//THINGS TO MAKE
    //copy assignment operator operator=
    //int remove(keytype K);

#include <stdlib.h>
#include <iostream>
using namespace std; 

enum Color {red, black};

template<typename keytype, typename valuetype>
class RBTree{
    private:
        struct Node{
            keytype key;
            valuetype value;
            bool color;
            int leftSize;
            int rightSize;
            Node *left, *right, *parent;
            Node (){
                this->right = NULL;
                this->left = NULL;
                this->parent = NULL;
                this->color = black;
                // this->leftSize = 0;
                // this->rightSize = 0; 
            }
        }; 
        Node *root;
        Node *Tnil;

    public:
        int TreeSize;
        RBTree(){
            Tnil = new Node;
            root = Tnil;
            TreeSize = 0;
        }

        //copy constructor MAY BE WRONG
        Node *copyHelper(const Node *copy){
            if (copy){
                insert(copy->key, copy->value);
                copyHelper(root->left);
                copyHelper(root->right);
            }
        }
        RBTree(const RBTree<keytype, valuetype>& copy) {
            root = Tnil;
            copyHelper(copy.root);
        }

        //destructor MAY BE WRONG  
        void fuckingDelete(Node *&root){
            if (root != Tnil){
                fuckingDelete(root->left);
                fuckingDelete(root->right);
                delete root;
            }
        }
        ~RBTree(){
            fuckingDelete(root);
            delete Tnil;
        }
        
        Node *bstInsert(Node *root, Node *pt){
            if (root == Tnil){ 
                return pt;
            }

            if (pt->key < root->key){
                root->leftSize++;
                root->left = bstInsert(root->left, pt);
                root->left->parent = root;
            }
            else if (pt->key > root->key){
                root->rightSize++;
                root->right = bstInsert(root->right, pt);
                root->right->parent = root;
            }

            return root;
        }
        //definitely need to make sure im changing rightSize coreectly in rotate left and right functions
        void rotateLeft(Node *&pt){
            Node *tempRight = pt->right;
            tempRight->leftSize = pt->leftSize + tempRight->leftSize + 1;
            pt->rightSize = pt->rightSize - pt->rightSize + tempRight->leftSize;
            pt->right = tempRight->left;
            if (pt->right != Tnil){
                pt->right->parent = pt;
            }
            tempRight->parent = pt->parent;
            if (pt->parent == Tnil){
                root = tempRight;
            }
            else if (pt == pt->parent->left){
                pt->parent->left = tempRight;
            }
            else {
                pt->parent->right = tempRight;
            }
            tempRight->left = pt;
            pt->parent = tempRight;
        }
        void rotateRight(Node *&pt){
            Node *tempLeft = pt->left;
            pt->leftSize = pt->leftSize - tempLeft->leftSize - 1;
            tempLeft->rightSize = pt->rightSize - tempLeft->rightSize + 1 + pt->leftSize;
            pt->left = tempLeft->right;
            if (pt->left != Tnil){
                pt->left->parent = pt;
            }
            tempLeft->parent = pt->parent;
            if (pt->parent == Tnil){
                root = tempLeft;
            }
            else if (pt == pt->parent->left){
                pt->parent->left = tempLeft;
            }
            else {
                pt->parent->right = tempLeft;
            }
            tempLeft->right = pt;
            pt->parent = tempLeft;
        }
        void insertFixUp(Node*&pt){
            Node *parentPt = Tnil;
            Node *grandParentPt = Tnil;

            while ((pt != root) && (pt->color != black) && (pt->parent->color == red)){
                parentPt = pt->parent;
                grandParentPt = pt->parent->parent;

                //Parent of pt is left child of grandParent 
                if (parentPt == grandParentPt->left){
                    Node *unclePt = grandParentPt->right;
                    //uncle is red
                    if ((unclePt != Tnil) && (unclePt->color == red)){
                        grandParentPt->color = red;
                        parentPt->color = black;
                        unclePt->color = black;
                        pt = grandParentPt;
                    }
                    else {
                    //pt is right child so leftRotation
                        if (pt == parentPt->right){
                            rotateLeft(parentPt);
                            pt = parentPt;
                            parentPt = pt->parent;
                        }
                    //pt is left child so rightRotation
                        rotateRight(grandParentPt);
                        swap(parentPt->color, grandParentPt->color);
                        pt = parentPt;
                    }
                }

                else {
                    Node *unclePt = grandParentPt->left;

                    if ((unclePt != Tnil) && (unclePt->color == red)){
                        grandParentPt->color = red;
                        parentPt->color = black;
                        unclePt->color = black;
                        pt = grandParentPt;
                    }
                    else {
                    //pt is left child so rightRotation
                        if (pt == parentPt->left){
                            rotateRight(parentPt);
                            pt = parentPt;
                            parentPt = pt->parent;
                        }
                    //pt is right child so leftRotation
                        rotateLeft(grandParentPt);
                        swap(parentPt->color, grandParentPt->color);
                        pt = parentPt;
                    }
                }
            }
            root->color = black;
        }
        void insert(keytype key, valuetype value){ //will have to change key and value to 'keytype K' and 'valuetype V'
            Node *pt = new Node;
            pt->key = key;
            pt->value = value;
            pt->color = red;
            pt->leftSize = 0;
            pt->rightSize = 0;
            pt->left = Tnil;
            pt->right = Tnil;
            pt->parent = Tnil;
            root = bstInsert(root, pt);
            insertFixUp(pt);
            TreeSize++;
        }

        RBTree(keytype K[], valuetype V[], int s){
            root = Tnil;
            TreeSize = 0;
            for (int i = 0; i < s; i++){
                insert(K[i], V[i]);
            }
        }

        void inorderHelper(Node *n){
            Node *temp = n;
            if (temp == Tnil){
                return;
            }
            inorderHelper(temp->left);
            cout << temp->key << " ";
            inorderHelper(temp->right);
        }
        void inorder(){
            inorderHelper(root);
            cout << endl;
        }

        void preorderHelper(Node* n){
            Node *temp = n;
            if (temp == Tnil){
                return;
            }
            cout << temp->key << " ";
            preorderHelper(temp->left);
            preorderHelper(temp->right);
        }
        void preorder(){
            preorderHelper(root);
            cout << endl;
        }

        void postorderHelper(Node *n){
            Node *temp = n;
            if (temp == Tnil){
                return;
            }
            postorderHelper(temp->left);
            postorderHelper(temp->right);
            cout << temp->key << " ";
        }
        void postorder(){
            postorderHelper(root);
            cout << endl;
        }

        int size(){
            return TreeSize;
        }
        
        int rank(keytype K){
            Node *temp = root;
            int rankNumber = 1;
            while (temp != Tnil){
                if (K == temp->key){
                    rankNumber = rankNumber + temp->leftSize;
                    return rankNumber;
                }
                else if (K > temp->key){
                    rankNumber = rankNumber + temp->leftSize + 1;
                    temp = temp->right;
                }
                else if (K < temp->key){
                    temp = temp->left;
                }
            }
            return 0;
        }

        valuetype * search(keytype K){
            Node *s = root;
            while (s != Tnil){
                if (K < s->key){
                    s = s->left;
                }
                else if (K > s->key){
                    s = s->right;
                }
                else if (K == s->value){
                    return &s->value;
                }
                else {
                    break;
                }
            }
            return NULL;
        }

        Node *selectHelper(int pos){
            if (pos < TreeSize){
                Node *temp = root;
                int rankNumber = 1;
                while (temp != Tnil){
                    if (temp->leftSize + rankNumber == pos){
                        return temp;
                    }
                    else if (pos > temp->leftSize + rankNumber){
                        rankNumber = rankNumber + temp->leftSize + 1;
                        temp = temp->right;
                    }
                    else if (pos < temp->leftSize + rankNumber){
                        temp = temp->left;
                    }
                    else {
                        break;
                    }
                }
            }
            return NULL;
        }
        keytype select(int pos){
            Node *selected = selectHelper(pos);
            return selected->key;
        }

        //minValue helps predecessor() find the biggest node in the left subtree of node sent to it
        Node * minValue(Node *n){
            Node *min = n;
            while (min->left != Tnil){
                min = min->left;
            }
            return min;
        }
        keytype *successor(keytype K){
            int Srank = rank(K);
            Node *successorNode = selectHelper(Srank+1);
            return &successorNode->key;
        }
        //maxValue helps predecessor() find the biggest node in the left subtree of node sent to it
        keytype *predecessor(keytype K){
            int Krank = rank(K);
            Node *temp = selectHelper(Krank-1);
            return &temp->key;
        }        

        void RBTransplant(Node* u, Node* v){
            if (u->parent == Tnil){
                root = v;
            }
            else if(u == u->parent->left){
                u->parent->left = v;
            }
            else {
                u->parent->right = v;
            }
            v->parent = u->parent;
        }
        void RBDeleteFixUp(Node *x){
            Node *w;
            while ((x != root) && (x->color == black)){
                if (x == x->parent->left){
                    w = x->parent->right;
                    if (w->color == red){
                        w->color = black;
                        x->parent->color = red;
                        rotateLeft(x->parent);
                        w = x->parent->right;
                    }
                    if ((w->left->color == black) && (w->right->color == black)){
                        w->color = red;
                        x = x->parent;
                    }
                    else {
                        if (w->right->color == black){
                            w->left->color = black;
                            w->color = red;
                            rotateRight(w);
                            w = x->parent->right;
                        }
                        w->color = x->parent->color;
                        x->parent->color = black;
                        w->right->color = black;
                        rotateLeft(x->parent);
                        x = root;
                    }
                }
                else {
                    w = x->parent->left;
                    if (w->color == red){
                        w->color = black;
                        x->parent->color = red;
                        rotateRight(x->parent);
                        w = x->parent->left;
                        cout << w->key << endl;
                    }
                    if ((w->right->color == black) && (w->left->color == black)){
                        w->color = red;
                        x = x->parent;
                    }
                    else {
                        if (w->left->color == black){
                            w->right->color = black;
                            w->color = red;
                            rotateLeft(w);
                            w = x->parent->left;
                        }
                        w->color = x->parent->color;
                        x->parent->color = black;
                        w->left->color = black;
                        rotateRight(x->parent);
                        x = root;
                    }
                }
            }
            x->color = black;
        }
        int remove(keytype K){
            Node *temp = root;
            Node *y;
            Node *x;
            while (temp != Tnil){
                if (K > temp->key){
                    temp = temp->right;
                }
                else if (K < temp->key){
                    temp = temp->left;
                }
                else if (K == temp->key){
                    Node *z = temp;
                    y = z;
                    bool yOriginalColor = y->color;
                    if (z->left == Tnil){
                        x = z->right;
                        RBTransplant(z, z->right);
                    }
                    else if(z->right == Tnil){
                        x = z->left;
                        RBTransplant(z, z->left);
                    }
                    else {
                        y = minValue(z->right);
                        yOriginalColor = y->color;
                        x = y->right;
                        if (y->parent == z){
                            x->parent = y;
                        }
                        else {
                            RBTransplant(y, y->right);
                            y->right = z->right;
                            y->right->parent = y;
                        }
                        RBTransplant(z, y);
                        y->left = z->left;
                        y->left->parent = y;
                        y->color = z->color;
                    }
                    if (yOriginalColor == black){
                        RBDeleteFixUp(x);
                    }
                    TreeSize = TreeSize - 1;
                    return 1;
                }
                else {
                    break;
                }
            }
            return 0;
        }
};