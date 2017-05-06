#include<iostream>
using namespace std;

int main()
{
    cout<<"enter the number"<<endl;
    unsigned int a;
    cin>>a;

    unsigned int mask = 1;
    unsigned int ones = 0;
    for(int i=0;i<sizeof(int)*8;i++)
    {
        if((a & (mask<< i)) != 0)
            ones++;
    }
    cout<<"mask "<<mask<<endl;

    cout<<"Number of ones in "<<a<<" is "<<ones<<endl;
}
