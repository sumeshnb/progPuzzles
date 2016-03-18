#include<iostream>

using namespace std;

int main()
    try{
        cout<<"hello"<<endl;
    }
catch(...){
    cout<<"some exception"<<endl;
}

/* 
 * the above same principle can be applied
 * incase of constructor initializer lists
 * ie, to catch those exceptions which occur
 * during the execution of constructor 
 * initializer lists
 */
