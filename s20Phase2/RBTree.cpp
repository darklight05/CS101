//THINGS TO MAKE
    //~RBTree(); 
    //int remove(keytype K);
    //int rank(keytype K); <----woring on this now
    //keytype select(int pos);
    //keytype *successor(keytype K)
    //keytype *predecessor(keytype K)

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
            Node *left, *right, *parent;
            Node (keytype key, valuetype value){
                this->key = key;
                this->value = value;
                left = right = parent = NULL;
                this->color = red;
                leftSize = 0;
            }
        }; 
        
        Node *root;

    public:
        int TreeSize;
        RBTree(){
            root = NULL;
            TreeSize = 0;
        }

        Node *bstInsert(Node *root, Node *pt){
            if (root == NULL){ 
                return pt;
            }

            if (pt->key < root->key){
                root->left = bstInsert(root->left, pt);
                root->left->parent = root;
                root->leftSize = root->leftSize+1;
            }
            else if (pt->key > root->key){
                root->right = bstInsert(root->right, pt);
                root->right->parent = root;
            }

            return root;
        }
        void rotateLeft(Node *&root, Node *&pt){
            Node *tempRight = pt->right;
            //GET RANKED MF
            tempRight->leftSize = pt->leftSize + tempRight->leftSize + 1;
            pt->right = tempRight->left;
            if (pt->right != NULL){
                pt->right->parent = pt;
            }
            tempRight->parent = pt->parent;
            if (pt->parent == NULL){
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
        void rotateRight(Node *&root, Node *&pt){
            Node *tempLeft = pt->left;
            //GET RANKED MF
            pt->leftSize = pt->leftSize - tempLeft->leftSize;
            pt->left = tempLeft->right;
            if (pt->left != NULL){
                pt->left->parent = pt;
            }
            tempLeft->parent = pt->parent;
            if (pt->parent == NULL){
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
        void insertFixUp(Node *&root, Node*&pt){
            Node *parentPt = NULL;
            Node *grandParentPt = NULL;

            while ((pt != root) && (pt->color != black) && (pt->parent->color == red)){
                parentPt = pt->parent;
                grandParentPt = pt->parent->parent;

                //Parent of pt is left child of grandParent 
                if (parentPt == grandParentPt->left){
                    Node *unclePt = grandParentPt->right;
                    //uncle is red
                    if ((unclePt != NULL) && (unclePt->color == red)){
                        grandParentPt->color = red;
                        parentPt->color = black;
                        unclePt->color = black;
                        pt = grandParentPt;
                    }
                    else {
                    //pt is right child so leftRotation
                        if (pt == parentPt->right){
                            rotateLeft(root, parentPt);
                            pt = parentPt;
                            parentPt = pt->parent;
                        }
                    //pt is left child so rightRotation
                        rotateRight(root, grandParentPt);
                        swap(parentPt->color, grandParentPt->color);
                        pt = parentPt;
                    }
                }

                else {
                    Node *unclePt = grandParentPt->left;

                    if ((unclePt != NULL) && (unclePt->color == red)){
                        grandParentPt->color = red;
                        parentPt->color = black;
                        unclePt->color = black;
                        pt = grandParentPt;
                    }
                    else {
                    //pt is left child so rightRotation
                        if (pt == parentPt->left){
                            rotateRight(root, parentPt);
                            pt = parentPt;
                            parentPt = pt->parent;
                        }
                    //pt is right child so leftRotation
                        rotateLeft(root, grandParentPt);
                        swap(parentPt->color, grandParentPt->color);
                        pt = parentPt;
                    }
                }
            }
            root->color = black;
        }
        void insert(keytype key, valuetype value){ //will have to change key and value to 'keytype K' and 'valuetype V'
            Node *pt = new Node(key, value);
            root = bstInsert(root, pt);
            insertFixUp(root, pt);
            TreeSize++;
        }

        RBTree(keytype K[], valuetype V[], int s){
            root = NULL;
            TreeSize = 0;
            for (int i = 0; i < s; i++){
                insert(K[i], V[i]);
            }
        }

        void inorderHelper(Node *root){
            if (root == NULL){
                return;
            }
            inorderHelper(root->left);
            cout << root->key << " ";
            inorderHelper(root->right);
        }
        void inorder(){
            inorderHelper(root);
        }

        void preorderHelper(Node* root){
            if (root == NULL){
                return;
            }
            cout << root->key << " ";
            preorderHelper(root->left);
            preorderHelper(root->right);
        }
        void preorder(){
            preorderHelper(root);
        }

        void postorderHelper(Node *root){
            if (root == NULL){
                return;
            }
            postorderHelper(root->left);
            postorderHelper(root->right);
            cout << root->key << " ";
        }
        void postorder(){
            postorderHelper(root);
        }

        int size(){
            return TreeSize;
        }
        
        int rank(keytype K){
            Node *p = root;
            while (p != NULL){
                cout << "inside while loop" << endl;
                if (p->key == K){
                    // cout << "here" << endl;
                    return (p->leftSize+1);
                }

                else if (p->key < K){
                    p = p->left;
                }
                else if (p->key > K){
                    cout << p->leftSize << endl;
                    p = p->right;
                    p->leftSize = p->leftSize + p->parent->leftSize + 1;
                }
            }
            return 0;
        }

        valuetype * search(keytype K){
            static valuetype * searchingFor;
            while (root != NULL){
                if (root->key == K){
                    searchingFor = &root->value;
                    return searchingFor;
                }
                else if (root->key > K){
                    root = root->right;
                }
                else if (root->key < K){
                    root = root->left;
                }
            }
            return NULL;
        }
};