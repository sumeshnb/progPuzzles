//
// Created by sumesh on 1/8/2016.
//


#include <iostream>
using namespace std;
template < class T , class U>
auto mul(T x, U y) -> decltype(x*y){
    return x*y;
};


int main(){
    int a{10};
    float b{10.0};
    cout<<mul(a,b);
}
