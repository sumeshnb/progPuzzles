#include<iostream>
using namespace std;

class Fred{
    const int size;
    public:
    Fred(int sz);
    void print() const;
};

Fred::Fred(int sz):
    size(sz){
    }
void Fred::print() const{ cout<<size<<endl;}

int main(){
    Fred a(1), b(2), c(3);
    a.print(), b.print(), c.print();
}
