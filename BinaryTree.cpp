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
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    void orderStatistics(unsigned int order);
    T predecessor(T data);
    T successor(T data);

private:
    node<T> * root;
    void updateSubtreeSize(node<T>* n, bool increase=true);
    void inorderTraversalHelper(node<T>* root);
    void postorderTraversalHelper(node<T>* root);
    void preorderTraversalHelper(node<T>* root);
    node<T>* predecessorHelper(T data);
    node<T> * successorHelper(T n);
    node<T>* getNodePtr(T data);
    node<T>* orderStatisticsHelper(node<T>*, unsigned int order);
};

template <typename T>
binaryTree<T>::binaryTree():root(nullptr) {
}

template<typename T>
void binaryTree<T>::orderStatistics(unsigned int order){
    node<T>* ptr = orderStatisticsHelper(root, order);
    if(ptr){
        cout<<order<<"th smallest item: "<<ptr->data;
    }else{
        cout<<"item could not be retrieved as size of tree is less than "<<order<<endl;
    }
}

template<typename T>
node<T>* binaryTree<T>::orderStatisticsHelper(node<T>* root, unsigned int order){

    if(root == nullptr){
        return nullptr;
    }

    if(root->left && root->right){

        if(root->left->subtree_size + 1 == order){
            //yes, root is the one which we are searching
            return root;
        }else if(root->left->subtree_size+1 > order){
            //root is of higher order so we have to search in left subtree
            return orderStatisticsHelper(root->left, order);
        }else{
            //root is of lower order so search in right subtree
            return orderStatisticsHelper(root->right, order - (root->left->subtree_size + 1));
        }

    }else if(root->left){

        if(root->left->subtree_size + 1 == order){
            //yes, root is the one which we are searching
            return root;
        }else if(root->left->subtree_size+1 > order){
            //root is of higher order so we have to search in left subtree
            return orderStatisticsHelper(root->left, order);
        }else{
            //no right child for root
            return nullptr;
        }

    }else if(root->right){
        if(1 == order){
            //yes, root is the one which we are searching
            return root;
        }else{
            //root is of lower order so search in right subtree
            return orderStatisticsHelper(root->right, order - 1);
        }
    }else{
        if(1 == order){
            return root;
        }else{
            return nullptr;
        }
    }

}




//updates subtree size in an upward fashion
//after insertion of each node
//this operation does not change the
//complexity of insertion, ie, O(height)
template<typename T>
void binaryTree<T>::updateSubtreeSize(node<T> *n, bool increase) {
    //cout<<"updateSubtreeSize"<<endl;
    node<T> *p = n;

    if(increase){
        //insert node case
        //set current nodes size to 1
        p->subtree_size = 1;
    }else{
        //delete node case
        p->subtree_size--;
    }

    p = p->parent;

    while(p){
        //cout<<"updateSubtreeSize loop"<<endl;
        increase?p->subtree_size++:p->subtree_size--;
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
        node<T> *n = new node<T>();
        n->subtree_size = 1;
        n->data = a;
        n->left = n->right =  n->parent = nullptr;
        root = n;
        return;
    }

    while(r){
        if(a < r->data){
            if(r->left == nullptr){
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
            if(r->right == nullptr){
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
T binaryTree<T>::predecessor(T data){

     node<T>* p = predecessorHelper(data);
     if(p){
         return p->data;
     }else{
         //return the same data to indicate 
         //no predecessor present
         return data;
     }
}

template<typename T>
node<T>* binaryTree<T>::predecessorHelper(T data){
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
    // with lower value is found

    node<T>* t = r;
    while(t){
        if(t->data < r->data){//assume no duplicate keys are present in the tree
            //we found a parent with lower data
            return t;
        }
        t = t->parent;
    }

    //the node does not have predecessor, so it is the smallest in tree
    return nullptr;
}

template<typename T>
T binaryTree<T>::successor(T data){

     node<T>* p = successorHelper(data);
     if(p){
         return p->data;
     }else{
         //return the same data to indicate 
         //no predecessor present
         return data;
     }
}

template<typename T>
node<T>* binaryTree<T>::successorHelper(T data){
    node<T> * r = getNodePtr(data);

    //case-1: node has right subtree
    if(r->right){
        //return the node which has smallest value in right subtree
        node<T> *k = r->right;
        while(k->left){
            k = k->left;
        }
        return k;
    }

    //case-2: node does not have right subtree
    // traverse up the tree untill a node 
    // with higher value is found

    node<T>* t = r;
    while(t){
        if(t->data > r->data){//assume no duplicate keys are present in the tree
            //we found a parent with lower data
            return t;
        }
        t = t->parent;
    }

    //the node does not have a successor, the largest value in tree 
    return nullptr;
}


template <typename T>
node<T>* binaryTree<T>::getNodePtr(T data){
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

    if(r == nullptr){
        cout<<"node not found!!"<<endl;
        return nullptr;
    }
    return r;
}


template <typename T>
void binaryTree<T>::deleteNode(T data) {

    //find out the node

    node<T> * r = getNodePtr(data);
    if(r == nullptr){
        return;
    }
   
    //1. Happy case - the node to delete is a leaf
    //r is the node which have data as value

    if(r->left== nullptr && r->right == nullptr){

        //root is a special case!
        if(r == root){
            //the node to delete is root as well as leaf, ie, only one node is present in tree
            delete r;
            root = nullptr;
            //no need to update subtree size
            return;
        }

        if(r->parent->left == r){
            //r is left child of its parent
            r->parent->left = nullptr;
        }else{
            //r is right child of its parent
            r->parent->right = nullptr;
        }
        updateSubtreeSize(r->parent, false);//false = decrease subtree size

        delete(r);
        return;
    }

    //2. medium difficult case, the node to delete
    // has one child - in this case , just delete
    // the node and re-wire the pointers

    if(r->left == nullptr || r->right == nullptr){
        if(r != root){
            if(r->parent->left == r){//r is the left child of its parent
                r->parent->left = r->left==nullptr?r->right:r->left;
            }else{
                r->parent->right = r->left==nullptr?r->right:r->left;
            }

            //rewire parent pointer
            r->left==nullptr?r->right->parent = r->parent:r->left->parent = r->parent;
        }else{
            if(r->left){
                r->left->parent = nullptr;
                root = r->left;
            }else{
                r->right->parent = nullptr;
                root = r->right;
            }
        }
        updateSubtreeSize(r->parent,false);
        //finally delete r
        delete(r);
        return;
    }

    //case 3. most difficult case: the node is neither leaf nor has only one child
    //ie , the node has two children
    //Logic: swap this node and its inorder predecessor, now the node has become
    //a leaf node. Delete the node - simple!

    node<T>* pred = predecessorHelper(data);
    //cout<<"predecessor="<<pred->data;

    //exchange pred->data and data
    T temp = pred->data;
    pred->data = r->data;
    r->data = temp;

    //now delete pred , which should be a leaf
    if(pred->parent->right == pred){
        pred->parent->right = nullptr;
    }else{
        pred->parent->left = nullptr;
    }
    updateSubtreeSize(pred->parent, false);
    delete(pred);
    return;
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
    cout<<root->data<<" ";
    inorderTraversalHelper(root->right);
}

template <typename T>
void binaryTree<T>::postorderTraversal() {
    postorderTraversalHelper(root);
}

template <typename T>
void binaryTree<T>::postorderTraversalHelper(node<T> * root){
    if(root == nullptr){
        return ;
    }
    postorderTraversalHelper(root->left);
    postorderTraversalHelper(root->right);
    cout<<root->data<<" ";
}

template <typename T>
void binaryTree<T>::preorderTraversal() {
    preorderTraversalHelper(root);
}

template <typename T>
void binaryTree<T>::preorderTraversalHelper(node<T> * root){
    if(root == nullptr){
        return ;
    }
    cout<<root->data<<" ";
    preorderTraversalHelper(root->left);
    preorderTraversalHelper(root->right);
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
        cout << "1. insert node" << endl;
        cout << "2. delete node" << endl;
        cout << "3. inorder traversal " << endl;
        cout << "4. pre-order traversal " << endl;
        cout << "5. post-order traversal " << endl;
        cout << "6. order statistics(Eg. 24th smallest element?)" << endl;
        cout << "7. rank of a node" << endl;
        cout << "8. predecessor of a node" << endl;
        cout << "9. successor of a node" << endl;
        cout << "10. quit application" << endl;

        cin.clear();
        cin.ignore();

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
            case 3:
                cout<<"inorder traversal...."<<endl;
                tree.inorderTraversal();
                break;
            case 4:
                cout<<"pre-order traversal..."<<endl;
                tree.preorderTraversal();
                break;
            case 5:
                cout<<"post-order traversal.."<<endl;
                tree.postorderTraversal();
                break;
            case 6:
                cout<<"enter the order statistics to find out"<<endl;
                unsigned int order_statistics;
                cin>>order_statistics;
                tree.orderStatistics(order_statistics);
                break;
            case 7:
                break;
            case 8:
                cout<<"Enter node"<<endl;
                int pred;
                cin>>pred;
                cout<<"Predecessor of "<<pred<<"is "<<tree.predecessor(pred)<<endl;
                break;
            case 9:
                cout<<"Enter node"<<endl;
                int succ;
                cin>>succ;
                cout<<"Successor of "<<succ<<"is "<<tree.successor(succ)<<endl;
                break;
            case 10:
                cout<<"exiting application"<<endl;
                exit(0);
                break;
            default:
                cout<<"invalid option"<<endl;
        }

    }while( option!=10);

}
