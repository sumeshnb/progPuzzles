// Created by Sumesh Balan on 1/12/16.
#include <vector>
#include <iostream>

using namespace std;

class Fred{
public:
    Fred(int i)
    :j(i){
        cout<<"fred constructor"<<endl;};
    Fred(const Fred& f){
        j = f.j;
        cout<<"copy constructor called"<<endl;
    }
private:
    int j;
};

int main(){
    //Fred f[10];
    std::vector<Fred> v(11,Fred(7));

}
