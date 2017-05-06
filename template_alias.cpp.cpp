//
// Created by sumesh on 1/8/2016.
//


#include <vector>
#include <iostream>
using namespace std;

int main(){
    using intvec = vector<int,allocator<int>>;
    intvec a{1,2,3,4,5};
    //for(auto &i: a)cout<<i<<endl;
    for(auto &j: {1,2,3,4,5,6,7,8,9,10})cout<<j<<endl;
}

