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
    void updateSubtreeSize(node<T> * n);
    void inorderTraversal();

private:
    node<T> * root;
    void inorderTraversalHelper(node<T> *root);
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

    cout<<"nodes inserted..."<<endl;

    //just do an inorder traversal of the tree
    tree.inorderTraversal();

}