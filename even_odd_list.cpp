//
// Created by sumesh on 12/25/2015.
//
#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node * next;
}node;

node * evenOddList(node *head);

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
    /*node *temp = firstHead;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;*/

    node *evenodd= evenOddList(firstHead);

    node *temp = evenodd;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}


node * evenOddList(node *head){

    if(!head){
        return head;
    }

    node * even = head;
    node * odd = head->next;
    node * oddstart = odd;
    node * prev_even;

    while(even && odd && even->next && odd->next ){

        even->next = even->next->next;
        prev_even = even;
        even = even->next;
        odd->next = odd->next->next;
        odd = odd->next;
    }

    if(even){
        even->next = oddstart;
    }else{
        prev_even->next = oddstart;
    }

    return head;
}
