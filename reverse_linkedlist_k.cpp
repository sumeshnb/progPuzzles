//
// Created by sumesh on 12/25/2015.
//
#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node * next;
}node;

node *reverseLinkedList(node *head);

node * reverseK(node *L,int k);

int main() {
    //read two lists
    cout << "enter nodes in first list" << endl;
    int i;
    node *firstHead = nullptr;
    node *first = nullptr;

    while (cin >> i) {
        node *newItem = new node();
        newItem->data = i;
        newItem->next = nullptr;
        if (firstHead == nullptr) {//executed only during first iteration
            firstHead = newItem;
            first = firstHead;
            continue;
        }
        first->next = newItem;
        first = newItem;
    }

    //print the list
    node *temp = firstHead;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cin.clear();
    cin.ignore();

    cout<<"enter k"<<endl;
    cin>>i;

    node *rlist = reverseK(firstHead,i);

    temp = rlist;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}

node *reverseLinkedList(node *head){
    node * prev= nullptr;
    node * curr = head;
    node * temp = nullptr;
    while(curr){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return  prev;
}

node * reverseK(node *L,int k){

    node * post = L;
    node * prev_post = nullptr;
    node * prev = L;
    node * prev_prev = nullptr;
    bool firstTime = true;

    while(prev){
        int i = k;
        while(i){

            prev_post = post;
            post = post->next;
            --i;
            if(!post){
                break;
            }
        }

        if(i){
            return L;
        }

        prev_post->next = nullptr;

        reverseLinkedList(prev);

        if(prev_prev){
            prev_prev->next = prev_post;
        }

        if(firstTime){
            L = prev_post;
            firstTime = false;
        }

        prev->next = post;
        prev_prev = prev;
        prev = post;
    }
    return L;
}
