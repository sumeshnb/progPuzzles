//
// Created by sumesh on 1/8/2016.
//

#include <iostream>

using namespace std;
struct s{
    int a;
    char c;
    int b;
};

int main(){
    cout<< sizeof(s)<<endl;
    static_assert(sizeof(s) == sizeof(int)+ sizeof(char) + sizeof(int), "unexpected paddding in struct s");
}
