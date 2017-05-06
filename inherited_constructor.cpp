//
// Created by sumesh on 1/8/2016.
//

#include <iostream>
using namespace std;

class base{
public:
    base(int ){//does not do anything
        cout<<"base constructor is called !!"<<endl;
    }
    base(double){
        cout<<"base float contructor is called!!!"<<endl;
    }
};

class derived:public base{
public:
    using base::base;
    int a{450};
};

int main()
{
    derived d(10.0);
    cout<<"derived.a="<<d.a<<endl;
}
