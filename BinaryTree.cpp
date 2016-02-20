//
// Created by Sumesh Balan on 1/24/16.
//

/*
 *  Binary Tree (unbalanced implementation)
 *  Augmented with subtree size
 *  Supports the following operations
 *  1. Read an initial set of nodes from command line separated by spaces and terminated by nonint character
 *  2. insert a node
 *  3. delete a node
 *  4. inorder traversal
 *  5. pre-order traversal
 *  6. post order traversal
 *  7. order statistics
 *  8. rank of an item
 *  9. predecessor
 *  10.successor
 *  11. quit application
 */
#include <memory>
#include <iostream>
using namespace std;

template <typename T>
class node{
public:
    T data;
    unsigned int subtree_size;
    node<T> *left, *right, *parent;
};


template <typename T>
class binaryTree{
public:
    binaryTree();
    void insertNode(T data);
    void deleteNode(T data);
    void updateSubtreeSize(node<T> * n);
    void inorderTraversal();
    T predecessor(T data);
    T successor(T data);

private:
    node<T> * root;
    void inorderTraversalHelper(node<T> *root);
    node<T> * predecessorHelper(node<T> * n);
    node<T> * successorHelper(node<T> * n);
    node<T>* getNodePtr(T data);
};

template <typename T>
binaryTree<T>::binaryTree():root(nullptr) {
}


//updates subtree size in an upward fashion
//after insertion of each node
//this operation does not change the
//complexity of insertion, ie, O(height)
template<typename T>
void binaryTree<T>::updateSubtreeSize(node<T> *n) {
    //cout<<"updateSubtreeSize"<<endl;
    node<T> *p = n;
    //set current nodes size to 1
    p->subtree_size = 1;
    p = p->parent;
    while(p){
        //cout<<"updateSubtreeSize loop"<<endl;
        p->subtree_size++;
        p = p->parent;
    }
}

/*
 * Insert a given node and update the subtree
 * sizes
 */
template <typename  T>
void binaryTree<T>::insertNode(T a) {

    //cout<<"insertNode"<<endl;
    node<T> * r = root;

    //Tree is empty
    if(!r){
        //cout<<"root case"<<endl;
        node<T> *n = new node<T>();
        n->subtree_size = 1;
        n->data = a;
        n->left = n->right =  n->parent = nullptr;
        root = n;
        return;
    }

    while(r){
        if(a < r->data){
            //cout<<"less"<<endl;
            if(r->left == nullptr){
                //cout<<"less and nullptr"<<endl;
                //place node here and break loop
                node<T>  *n = new node<T>();
                n->data = a;
                n->left = n->right = nullptr;
                n->parent = r;
                r->left = n;
                //update subtree sizes from current node to upward till root
                updateSubtreeSize(n);
                break;
            }
            r= r->left;
        }
        else{
            //cout<<"right"<<endl;
            if(r->right == nullptr){
                //cout<<"right and nullptr"<<endl;
                //place node here and break loop
                node<T>  *n = new node<T>();
                n->data = a;
                n->left = nullptr;
                n->right = nullptr;
                n->parent = r;
                r->right = n;
                //update subtree sizes from current node to upward till root
                updateSubtreeSize(n);
                break;
            }
            r= r->right;
        }
    }
}


template<typename T>
T binaryTree<T>::predesessor(T data){

     node<T>* p = predessorHelper(data);
     if(p){
         return p->data;
     }else{
         //return the same data to indicate 
         //no predecessor present
         return data;
     }
}

template<typename T>
T* binaryTree<T>::predecessorHelper(T data){
    node<T> * r = getNodePtr(data);

    //case-1: node has left subtree
    if(r->left){
        //return the node which has largest value in left subtree
        node<T> *k = r->left;
        while(k->right){
            k = k->right;
        }
        return k;
    }

    //case-2: node does not have left subtree
    // traverse up the tree untill a node 
    // with higher value is found

    node<T>* t = r;
    while(t){
        if(t->data < r->data){//assume no duplicate keys are present in the tree
            //we found a parent with lower data
            return t;
        }
        t = t->parent;
    }

    //only one node is present in the tree and which does not have predecessor
    return nullptr;
}

template <typename T>
void binaryTree<T>::getNodePtr(T data){
    //find out the node

    node<T> * r = root;

    while(r){
        if(r->data == data){
            break;
        }

        if(data < r->data){
            r = r->left;
        } else{
            r = r->right;
        }
    }

    if(!r){
        cout<<"node to delete is not found!!"<<endl;
        return nullptr;
    }
    return r;
}


template <typename T>
void binaryTree<T>::deleteNode(T data) {

    //find out the node

    node<T> * r = nullptr;
    if(r = getNodePtr(data)){
        //r is null pointer, data does not exist!!
        return;
    }
   
    //1. Happy case - the node to delete is a leaf
    //r is the node which have data as value

    if(r->left== nullptr && r->right == nullptr){

        if(r->parent->left == r){
            //r is left child of its parent
            r->parent->left = nullptr;
        }else{
            //r is right child of its parent
            r->parent->right == nullptr;
        }
        delete(r);

        return;
    }

    //2. medium difficult case, the node to delete
    // has one child - in this case , just delete
    // the node and re-wire the pointers

    if(r->left == nullptr || r->right == nullptr){

        if(r->parent->left == r){//r is the left child of its parent
            r->parent->left = r->left==nullptr?r->right:r->left;
        }else{
            r->parent->right = r->left==nullptr?r->right:r->left;
        }

        //rewire parent pointer
        r->left==nullptr?r->right->parent = r->parent:r->left->parent = r->parent;

        //finally delete r
        delete(r);
    }

    //case 3. most difficult case: the node is neither leaf nor has only one child
    //ie , the node has two children
    //Logic: swap this node and its inorder predecessor, now the node has become
    //a leaf node. Delete the node - simple!

    node<T>* pred = predecessorHelper(data);

    //exchange pred->data and data
    T temp = pred->data;
    pred->data = r->data;
    r->data = temp;

    //now delete pred , which should be a leaf

    pred->parent->right = nullptr;//pred should be the right child of its parent
    delete(pred);
}

template <typename T>
void binaryTree<T>::inorderTraversal() {
    inorderTraversalHelper(root);
}

template <typename T>
void binaryTree<T>::inorderTraversalHelper(node<T> * root){
    if(root == nullptr){
        return ;
    }
    inorderTraversalHelper(root->left);
    cout<<root->data;
    inorderTraversalHelper(root->right);
}



int main(){
    binaryTree<int> tree;
    cout<<" enter the elements in the tree"<<endl;

    int node_value;
    while(cin>>node_value) {
        //cout<<node_value<<endl;
        tree.insertNode(node_value);
    }

    cout<<"printing nodes in inorder traversal..."<<endl;

    //just do an inorder traversal of the tree
    tree.inorderTraversal();

    int option = 0;

    do {
        cout << "enter an option:" << endl;
        cout << "1. insert node" << end;
        cout << "2. delete node" << end;
        cout << "3. inorder traversal " << end;
        cout << "4. pre-order traversal " << end;
        cout << "5. post-order traversal " << end;
        cout << "6. order statistics(Eg. 24th smallest element?)" << endl;
        cout << "7. rank of a node" << endl;
        cout << "8. predecessor of a node" << endl;
        cout << "9. successor of a node" << endl;
        cout << "10. quit application" << endl;

        cin>>option;

        switch(option){
            case 1:
                cout<<"enter node value:";
                int node_value;
                cin>>node_value;
                tree.insertNode(node_value);
                break;
            case 2:
                cout<<"enter node value:"<<endl;
                int node_to_delete;
                cin>>node_to_delete;
                tree.deleteNode(node_to_delete);
                break;
            default:
                cout<<"invalid option"<<endl;


        }

    }while( option!=10)

}
