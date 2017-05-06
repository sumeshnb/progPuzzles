//
// Created by sumesh on 1/8/2016.
//


#include <iostream>
using namespace std;

struct base{
    void f(double){
        cout<<"base f(double) called"<<endl;
    }
};

struct derived: base{
    //name hiding - this f will hide all the base class names f
    //so , f(double) is not available here
    void f(int){
        cout<<"derived f(int) called"<<endl;
    }

    //inorder to bring f to derived class
    using base::f;
};


int main(){
    derived d;
    d.f(4.5);
}
