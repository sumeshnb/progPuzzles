#include <iostream>
using namespace std;

class Foo{
public:
    Foo(int i){
        cout<<"in constructor"<<endl;
        this->i = i;
    }
    Foo(const Foo& f){
        cout<<"in copy constructor"<<endl;
    }
    operator int(){return i;};
private:
    int i;
};

int main(){
    Foo x = 12;
    int i = x;
    cout<<i;
}
