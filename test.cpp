#include<iostream>
using namespace std;
class Test{
    public:
        Test();
        Test(int i);
        void printValue();
    private:
        int i;
};

Test::Test(){
    this->i = 10;
}
Test::Test(int i){
    this->i = i;
}
void Test::printValue(){
    cout<<"well, good start!"<<endl;
}

int main(){
    Test t;
    Test * ptr = new Test(11);
    ptr->printValue();
}
