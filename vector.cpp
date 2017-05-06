#include<vector>
#include<iostream>
#include<cstring>

using namespace std;
class test{
    public:
        char *ptr; 
    public:
        test()
            :ptr{new char[10]}{
                strcpy(ptr,"hello");
                cout<<"constructor called"<<endl;
            }
        test(const test& t){
            ptr = new char[10];
            strcpy(ptr,t.ptr);
            cout<<"copy constructor called"<<endl;
        }
        test(test &&t) noexcept {
            this->ptr = t.ptr;
            t.ptr = nullptr;
            cout<<"move constructor called"<<endl;
        }
        ~test(){
            cout<<"destructor called"<<endl;
            delete[] ptr;
        }
};

vector<test> function()
{
    vector<test> v;
    cout<<v.size()<<" "<<v.capacity()<<endl;
    v.push_back(test{});
    cout<<v.size()<<" "<<v.capacity()<<endl;
    v.push_back(test{});
    cout<<v.size()<<" "<<v.capacity()<<endl;
    return v;
}

int main()
{ 
    vector<test> v = function();
}
