//PREDECESSOR IS BREAKING BECAUSE RANK NUMBER IS NOT CORRECT

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
            Node *left, *right, *parent;
            Node (keytype key, valuetype value){
                this->key = key;
                this->value = value;
                left = NULL;
                right = NULL;
                parent = NULL;
                this->color = red;
                this->leftSize = 0;
            }
        }; 
        
        Node *root;

    public:
        int TreeSize;
        RBTree(){
            root = NULL;
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
            root = NULL;
            copyHelper(copy.root);
        }
        // &operator=(const RBTree<keytype, valuetype>copy&){
        //     if(this != &copy){
        //         fuckingDelete(root);
        //         root=NULL;
        //         copyHelper(copy.root);
        //     }
        //     return *this;
        // }

        //destructor MAY BE WRONG  
        void fuckingDelete(Node *&root){
            if (root){
                fuckingDelete(root->left);
                fuckingDelete(root->right);
                delete root;
            }
        }
        ~RBTree(){
            fuckingDelete(root);
            delete root;
        }
        
        Node *bstInsert(Node *root, Node *pt){
            if (root == NULL){ 
                return pt;
            }

            if (pt->key < root->key){
                root->leftSize++;
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
            pt->leftSize = pt->leftSize - tempLeft->leftSize - 1;
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
            Node *temp = root;
            if (temp == NULL){
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

        void preorderHelper(Node* root){
            Node *temp = root;
            if (temp == NULL){
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

        void postorderHelper(Node *root){
            Node *temp = root;
            if (temp == NULL){
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
            while (temp != NULL){
                if (temp->key == K){
                    rankNumber = temp->leftSize+1;
                    return rankNumber;
                }
                else if (K > temp->key){
                    temp = temp->right;
                    rankNumber = rankNumber + temp->leftSize + 1;
                    if (temp->key == K){
                        return rankNumber;
                    }
                }
                else if (K < temp->key){
                    temp = temp->left;
                    rankNumber = temp->leftSize +1;
                }
            }
            return 0;
        }

        valuetype * search(keytype K){
            Node *s = root;
            while (s != NULL){
                if (K < s->key){
                    s = s->left;
                }
                else if (K > s->key){
                    s = s->right;
                }
                else {
                    return &s->value;
                }
            }
            return NULL;
        }

        keytype select(int pos){
            if (pos < TreeSize){
                Node *temp = root;
                int rankNumber = 1;
                while (temp != NULL){
                    if (temp->leftSize + rankNumber == pos){
                        return temp->key;
                    }
                    else if (pos > temp->leftSize + rankNumber){
                        rankNumber = rankNumber + temp->leftSize + 1;
                        temp = temp->right;
                    }
                    else if (pos < temp->leftSize + rankNumber){
                        temp = temp->left;
                    }
                }
            }

        }

        //minValue helps predecessor() find the biggest node in the left subtree of node sent to it
        Node * minValue(Node *n){
            Node *min = n;
            while (min->left != NULL){
                min = min->left;
            }
            return min;
        }
        Node *successorHelper(keytype K){
                Node *temp = root;
                int rankNumber = 1;
                while (temp != NULL){
                    if (K > temp->key){
                        int prevLeftSize = temp->leftSize;
                        temp = temp->right;
                        temp->leftSize += prevLeftSize + 1;
                    }
                    else if (K < temp->key){
                        temp = temp->left;
                    }


                    else { 
                        Node *min;
                        rankNumber = rankNumber + temp->leftSize;
                        if (rankNumber == TreeSize){
                            return NULL;
                        }
                        
                        if (temp == root){
                            min = minValue(temp->right);
                            return min;
                        }

                        if (temp->right != NULL){
                            min = minValue(temp->right);
                            return min; 
                        }
                        if (temp->parent == temp->parent->parent->right){
                            min = temp->parent;
                            return min;
                        }

                        else {
                            Node *ancestor = temp->parent;
                            while (ancestor != ancestor->parent->left){
                                if (ancestor->parent == root){
                                    break;
                                }
                                ancestor = ancestor->parent;
                            }
                            if (ancestor->left == temp){
                                min = ancestor;
                                return min;
                            }
                            else if (ancestor->right == NULL){
                                min = ancestor;
                                return min; 
                            }
                            else if (temp == ancestor->right){
                                min = ancestor->parent;
                                return min; 
                            }
                            else {
                                cout << "last else" << endl;
                                min = minValue(ancestor->right);
                                return min; 
                            }                            
                        }
                    }
                }
        }
        keytype *successor(keytype K){
            Node *successorNode = successorHelper(K);
            return &successorNode->key;
        }
        //maxValue helps predecessor() find the biggest node in the left subtree of node sent to it
        Node * maxValue(Node *n){
            Node *max = n;
            while (max->right != NULL){
                max = max->right;
            }
            return max;
        }
        //doesnt work it (temp) is the left child of its parent who is a right child. i.e temp == temp->parent->left && temp->parent == temp->parent->parent->right
        keytype *predecessor(keytype K){
            Node *temp = root;
            int rankNumber = 1;

            while (temp != NULL){
                if (K > temp->key){
                    int prevLeftSize = temp->leftSize;
                    temp = temp->right;
                    temp->leftSize += prevLeftSize + 1;
                }
                else if (K < temp->key){
                    temp = temp->left;
                }


                else{
                    rankNumber = rankNumber + temp->leftSize;
                    if (rankNumber == 1){
                        return NULL;
                    }
                    Node *predecessorNode;
                    if (temp == root){
                        predecessorNode = maxValue(temp->left);
                        return &predecessorNode->key;
                    }
                    if (temp->left != NULL){
                        predecessorNode = maxValue(temp->left);
                        return &predecessorNode->key;
                    }
                    if(temp->parent == temp->parent->parent->left){
                        predecessorNode = temp->parent;
                        return &predecessorNode->key;
                    }
                    else {
                        Node *ancestor = temp->parent;
                        while (ancestor != ancestor->parent->right){
                            if (ancestor->parent == root){
                                break;
                            }
                            ancestor = ancestor->parent;
                        }
                        if (temp == ancestor->left){
                            predecessorNode = ancestor->parent;
                            return &predecessorNode->key;
                        }
                        else if (ancestor->left == NULL){
                            predecessorNode = ancestor;
                            return &predecessorNode->key;
                        }
                        else if (temp == ancestor->right){
                            predecessorNode = ancestor;
                            return &predecessorNode->key; 
                        }
                        else {
                            predecessorNode = maxValue(ancestor->left);
                            return &predecessorNode->key;
                        }
                    }
                }


            }
        }

        void RBTransplant(Node* u, Node* v){
            if (u->parent == NULL){
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
        int remove(keytype K){
            Node *z = root;
            while (z != NULL){
                if (K > z->key){
                    z = z->right;
                }
                else if (K < z->key){
                    z = z->left;
                }
                else {
                    //node to remove == y;
                    Node *y, x;
                    y = z;
                    bool yOriginalColor = y->color;
                    if (z->left == NULL){
                        x = z->right;
                        RBTransplant(z, z->left);
                    }
                    else if(z->right == NULL){
                        x = z->left;
                        RBTransplant(z, z->left);
                    }
                    else {
                        y = successorHelper(z->key);
                        yOriginalColor = y->color;
                        x = y->right;
                        //stopped at line
                        //if (y->)
                    }
                    //when done retrun 1;
                    return 1;
                }
            }
            return 0;
        }
};