#include<iostream>
#include<random>
using namespace std;

int main(){
    uniform_int_distribution<int> one_to_six{1,6};
    default_random_engine re{};
    for(int i=0;i<100;i++){
        int x = one_to_six(re);
        cout<<x<<endl;
    }
}
