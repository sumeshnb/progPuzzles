#include<iostream>
#include<vector>
#include<numeric>
#include<functional>
#include<limits>

using namespace std;

int findBiggestMinusOneMaxProduct(const vector<int> &v);
int main()
{
    cout<<"enter the input array"<<endl;

    vector<int> v;
    int a;
    while(cin>>a)
        v.push_back(a);

    cout<<"input arrray is"<<endl;

    for(int &i: v)
        cout<<i<<" ";
    cout<<endl;

    int max = findBiggestMinusOneMaxProduct(v);

    cout<<"max multiply is: "<<max<<endl;
}

int findBiggestMinusOneMaxProduct(const vector<int> &v)
{
    vector<int> L(v.size()),R(v.size());

    //back_inserter is fine, it will work when  the size is not reserved initially
    partial_sum(v.cbegin(),v.cend(),/*back_inserter(L)*/L.begin(),multiplies<int>());
    partial_sum(v.crbegin(),v.crend(),R.rbegin(),multiplies<int>());

#ifdef DEBUG
    for(int &i: L)
        cout<<i<<" ";
    cout<<endl;
    for(int &i: R)
        cout<<i<<" ";
    cout<<endl;
#endif
    int max_product = numeric_limits<int>::min();
    for(int i=0;i<v.size();i++)
    {
        int forward = i>0? L[i-1]:1;
        int backward = i+1 < v.size()? R[i+1]:1;
        max_product = max(max_product, forward * backward);
    }
    return max_product;
}
