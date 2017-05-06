//
// Created by sumesh on 12/24/2015.
//
#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node * next;
}node;

node *reverseLinkedList(node *head);

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

    node *rlist = reverseLinkedList(firstHead);

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
