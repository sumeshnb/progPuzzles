//
// Created by sumesh on 1/1/2016.
//

#include <stack>
#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;

class myStack{
private:
    stack<pair<int,int>> s;
public:
    myStack();
    int pop();
    int top();
    void push(int);
    int max();
    bool empty();
};

bool myStack::empty() {
    return s.empty();
}

myStack::myStack() {

}

void myStack::push(int x) {
    s.emplace(x, std::max(x, empty()?x:s.top().second));
    return;
}

int myStack::max() {
    if(!empty()) {
        return s.top().second;
    }
    throw length_error("empty stack");
}

int myStack::top(){
    if(!empty()){
        s.top().first;
    }
    throw length_error("empty stack");
}
int myStack::pop(){

    if(!empty()){

        throw length_error("empty stack");
    }

    int ret = s.top().first;
    s.pop();
    return ret;
}


int main(){

    myStack ms;
    cout<<"enter elements to the stack"<<endl;

    int k;
    while(cin>>k){
        ms.push(k);
    }

    cin.clear();
    cin.ignore();

    cout<<"current max is: "<<ms.max()<<endl;
    cout<<"enter some more elements"<<endl;

    while(cin>>k){
        ms.push(k);
    }

    cout<<"current max is: "<<ms.max();
}