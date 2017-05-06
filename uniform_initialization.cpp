#include<iostream>
#include <string>
#include<vector>
using namespace std;

void f(vector<string> a);

int main(){
    string a[] =  {"foo","bar"};
    cout<<a[0]<<endl;
    cout<<a[1]<<endl;
    cout<<"======================================"<<endl;
    vector<string> v = {"foo", "bar"};
    cout<<v[0]<<endl;
    cout<<v[1]<<endl;

    f({"hello", "world"});


}

void f(vector<string> a){
    //do something with string array
}
