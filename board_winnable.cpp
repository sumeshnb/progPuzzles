/* the book Elements of programming interviews uses
 * a slightly better method, in which sometimes we can 
 * stop the iteration before reaching the end of the 
 * array
 */
#include<iostream>
#include<vector>

using namespace std;

bool check_winnable(vector<int> & v);

int main()
{
    cout<<"enter the board position"<<endl;

    vector<int> v;
    int a;
    while(cin>>a)
        v.push_back(a);

    cout<<"board position is :"<<endl;

    for(int &i: v)
        cout<<i<<" ";
    cout<<endl;

    bool winnable = check_winnable(v);
    winnable?cout<<"you can win"<<endl:cout<<"you cannot win!"<<endl;
    return 0;
}

bool check_winnable(vector<int> & v)
{
    int d=1;
    for(int i=v.size()-2;i>=0;i--)
    {
        v[i] >= d?  d=1: d++;
    }

    return v.front() >= d?true:false;
}

