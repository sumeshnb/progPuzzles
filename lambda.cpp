#include<iostream>

int main(){
    auto hello = [] {
        std::cout<<"hello lambda"<<std::endl;
    };
    hello();

    []{
        std::cout<<"hello lambda again"<<std::endl;
    }();

    return 0;

}
