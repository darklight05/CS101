#include <stdlib.h>
#include <iostream>

//may have to use templates for key and value
    //template <typedef keyType>
    //template <typedef valueType>
//mmaybe like that idk
using namespace std; 


enum Color {red, black};

struct Node{
    int key;
    int value;
    int leftSize;
    bool color;
    Node *left, *right, *parent;

    Node (int key, int value){
        this->key = key;
        this->value = value;
        this->leftSize = 0;
        left = right = parent = NULL;
        this->color = red;
    }
};

class RBTree{
    private:
        Node *root;
    public:
        RBTree(){
           root = NULL; 
        }
        //change this to the keyType and valueType
        //RBTree(int K[], int V[], int s);

        Node *bstInsert(Node *root, Node *pt){
            if (root == NULL){
                return pt;
            }

            if (pt->key < root->key){
                root->left = bstInsert(root->left, pt);
                root->left->parent = root;
            }
            else if (pt->key > root->key){
                root->right = bstInsert(root->right, pt);
                root->right->parent = root;
            }

            return root;
        }
        void rotateLeft(Node *&root, Node *&pt){
            Node *tempRight = pt->right;
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
        void insert(int key, int value){ //will have to change key and value to 'keytype K' and 'valuetype V'
            Node *pt = new Node(key, value);
            root = bstInsert(root, pt);
            insertFixUp(root, pt);
        }

        RBTree(int K[], int V[], int s){
            for (int i = 0; i < s; i++){
                insert(K[i],V[i]);
            }
        }
        void inorderHelper(Node* root){
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
};