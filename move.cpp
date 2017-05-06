#include<vector>
#include<cstring>
#include<iostream>

using namespace std;

class test;//forward declaration
ostream& operator<<(ostream & x, test &y);

class test{
    public:
        char *ptr; 
    public:
        test()
            :ptr{new char[10]}{
                strcpy(ptr,"hello");
            }
        test(const test& t){
            ptr = new char[10];
            strcpy(ptr,t.ptr);
        }
        test(test &&t){
            cout<<"move constructor called"<<endl;
            this->ptr = t.ptr;
            t.ptr = nullptr;
        }
        ~test(){
            cout<<"destructor called"<<endl;
            delete[] ptr;
        }
};

int main(){
    test t{};
    vector<test> v;
    v.push_back(move(t));

    for(auto &o: v)
        cout<<o;
}

ostream& operator<<(ostream & x, test &y){
    x<<y.ptr<<endl;
    return x;
}
