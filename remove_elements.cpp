#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int removeElements(vector<int> & v,int a);

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

    cin.clear();
    cin.ignore();
    cout<<"enter k"<<endl;
    cin>>a;

    int newSize= removeElements(v,a);
    for(int i=0;i<newSize;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}

int removeElements(vector<int>  &v,int k)
{
    //start at first k and left shift all elemets till next k 
    //to the left
    int writeIndex = 0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i] != k){
            v[writeIndex++] = v[i];
        }
    }
    
    return writeIndex;
}


