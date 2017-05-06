#include<iostream>
#include<vector>
using namespace std;

void increment(vector<unsigned short> & a);
int main()
{
    unsigned short a;
    vector<unsigned short> v;

    cout<<"enter digits of the bignumber in msb first order"<<endl;
    while(cin>>a)
    { 
        if(a >= 0 && a <= 9)
            v.push_back(a);
    }

    cout<<"the number entered is: "<<endl;

    for(unsigned short &i: v)
        cout<<i;
    cout<<endl;

    increment(v);

    cout<<"incremented number is : "<<endl;

    for(unsigned short &i: v)
        cout<<i;
    cout<<endl;

    return 0;
}

void increment(vector<unsigned short> & a)
{
    unsigned short carry_in=0;
    for(int i=a.size() -1;i>=0; i--)
    {
        if((a[i] + 1) > 9){
            a[i] = 0;
        }else{
            a[i]++;
            break;
        }
    }
    if(a[0] == 0)
        a.insert(a.begin(),1);
}
        


