//
// Created by sumesh on 12/24/2015.
//

#include <iostream>

using namespace std;


typedef struct node{
    int data;
    node * next;
}node;

node * mergeSortedList(node *L, node *R);

int main(){
    //read two lists
    cout<<"enter nodes in first list"<<endl;

    int i;
    node *firstHead = nullptr;
    node *first= nullptr;

    while(cin>>i){
        node *newItem = new node();
        newItem->data = i;
        newItem->next = nullptr;
        if(firstHead == nullptr) {//executed only during first iteration
            firstHead = newItem;
            first = firstHead;
            continue;
        }
        first->next = newItem;
        first = newItem;
    }

    //print the list
    node *temp = firstHead;
    while(temp){
        cout<<temp->data<<endl;
        temp = temp->next;
    }

    //clear error and the character last read
    cin.clear();
    cin.ignore();

    cout<<"enter nodes in second list"<<endl;
    node *secondHead = nullptr;
    node *second= nullptr;

    while(cin>>i){
        node *newItem = new node();
        newItem->data = i;
        newItem->next = nullptr;
        if(secondHead == nullptr) {//executed only during first iteration
            secondHead = newItem;
            second= secondHead;
            continue;
        }
        second->next = newItem;
        second = newItem;
    }

    //print the list
    temp = secondHead;
    while(temp){
        cout<<temp->data<<endl;
        temp = temp->next;
    }

    node *head = mergeSortedList(firstHead,secondHead);

    //print elements of the merged list
    temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

    return 0;
}

node * mergeSortedList(node *L, node *R){
    node * newHead = nullptr;
    node * list = nullptr;

    while(L && R){
        if(L->data < R->data) {
            //first iteration of the loop
            if(!newHead){
                newHead = L;
                list = L;
                L = L->next;
                continue;
            }
            //second iteration of the loop onwards
            list->next = L;
            list = list->next;
            L=L->next;

        }else{
            //first iteration of the loop
            if(!newHead){
                newHead = R;
                list = R;
                R = R->next;
                continue;
            }
            //second iteration of the loop onwards
            list->next = R;
            list = list->next;
            R = R->next;
        }
    }

    //if L is not finished
    if(L){
        list->next = L;
    }else if(R){//R in not finished
        list->next = R;
    }else{//both L and R are finished
        list->next = nullptr;
    }

    return newHead;
}
