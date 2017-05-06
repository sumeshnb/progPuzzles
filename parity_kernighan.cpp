#include<iostream>
using namespace std;

int main()
{
    unsigned long a;
    cin>>a;
    
    int i=0;
    for(i=0;a;i++)
    {
        a &= a-1;
    }
    cout<<i<<endl;
}

