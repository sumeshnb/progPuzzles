//
// Created by sumesh on 12/27/2015.
//


#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

int main(){
    vector<int> v{1,2,2,6,6,3,3,4,89,0};
    sort(v.begin(),v.end());

    for(auto &a: v){
        cout<<a<<endl;
    }

    list<int> lst{999};
    unique_copy(v.begin(),v.end(),back_inserter(lst));
    cout<<lst.size()<<endl;
    for(auto &b: lst){
        cout<<b<<endl;
    }
    return 0;
}
