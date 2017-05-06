#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int removeDuplicateElements(vector<int> & v);

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
    int newSize=removeDuplicateElements(v);
    for(int i=0;i<newSize;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}

int removeDuplicateElements(vector<int>  &v)
{
    int writeIndex = 1;
    for(int i=1;i<v.size();i++)
    {
        if(v[i] != v[i-1]){
            v[writeIndex++] = v[i];
        }
    }
    
    return writeIndex;
}


