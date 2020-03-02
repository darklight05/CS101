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
    Color color;
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
        RBTree(int K[], int V[], int s){
            for (int i = 0; i < s; i++){
                insert(K[i], V[i]);
            }
        }
            //this builds the tree with the arrays K and V of size s

        Node *bstInsert(Node *root, Node *pt){
            if (root == NULL){
                return pt;
            }

            if (pt->key < root->key){
                root->left = bstInsert(root->left, pt);
                root->right->parent = root;
            }
            else if (pt->key > root->key){
                root->right = bstInsert(root->right, pt);
                root->left->parent = root;
            }

            return root;
        }
        void swap(Color &c1, Color &c2){
            Color temp = c1;
            c1 = c2;
            c2 = temp;
        }
        void rotateLeft(Node *&root, Node *&pt){
            Node *temp = pt->right;
            pt->right = temp->left;
            if (temp->left != NULL){
                temp->left->parent = pt;
            }
            temp->parent = pt->parent;
            if (pt->parent == NULL){
                root = temp;
            }
            else if (pt == pt->parent->left){
                pt->parent->left = temp;
            }
            else {
                pt->parent->right = temp;
            }
            temp->left = pt;
            pt->parent = temp;
        }
        void rotateRight(Node *&root, Node *&pt){
            Node *temp = pt->left;
            pt->left = temp->right;
            if (temp->right != NULL){
                temp->right->parent = pt;
            }
            temp->parent = pt->parent;
            if (pt->parent == NULL){
                root = temp;
            }
            else if (pt == pt->parent->right){
                pt->parent->right = temp;
            }
            else {
                pt->parent->left = temp;
            }
            temp->right = pt;
            pt->parent = temp;
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

        void inorderHelper(Node* root){
            if (root == NULL){
                return;
            }
        }

        void inorder(){
            inorderHelper(root);
        }
};