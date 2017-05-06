//
// Created by sumesh on 12/23/2015.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<int> v(10,5);

    cout<<v.at(0);
    cout<<v.at(9);

    try{
        cout<<v.at(9);

    }catch(std::exception & e){
        cout<<e.what()<<endl;
    }
}

