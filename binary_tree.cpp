//
// Created by Sumesh Balan on 1/10/16.
//
#include <memory>
#include <iostream>
using namespace std;

template <typename T>
class binarytree_node{
private:
    T data;
    binarytree_node<T> *left, *right;
public:
    void insertNode(T a);
    void inorderTraversal(binarytree_node<T> * root);
};

template <typename  T>
void binarytree_node<T>::insertNode(T a) {
    //find out the right position for a and place it there

    binarytree_node<T> *root = this;

    while(root){
        if(a<root->data){
            if(root->left == nullptr){
                //place node here and break loop
                binarytree_node<T>  *n = new binarytree_node<T>();
                n->data = a;
                n->left = nullptr;
                n->right = nullptr;
                root->left = n;
                break;
            }
            root = root->left;
        }
        else{
            if(root->right == nullptr){
                //place node here and break loop
                binarytree_node<T> *n = new binarytree_node<T>();
                n->data = a;
                n->left = nullptr;
                n->right = nullptr;
                root->right= n;
                break;
            }
            root = root->right;
        }
    }

}

template <typename T>
void binarytree_node<T>::inorderTraversal(binarytree_node<T> * root) {
    if(root == nullptr){
        return ;
    }
    inorderTraversal(root->left);
    cout<<root->data;
    inorderTraversal(root->right);
}


int main(){
    binarytree_node<int> tree;
    cout<<" enter the elements in the tree"<<endl;

    int node_value;
    while(cin>>node_value) tree.insertNode(node_value);

    cout<<"nodes inserted..."<<endl;

    //just do an inorder traversal of the tree
    tree.inorderTraversal(&tree);

}

