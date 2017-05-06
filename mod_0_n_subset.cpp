#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

vector<int> find_mod_0_n_subset(vector<int> & a);

int main()
{
    int a;
    vector<int> v;
    while(cin>>a)
        v.push_back(a);

    cout<<"input array: "<<endl;
    for(int &e: v)
        cout<<e<<" ";
    cout<<endl;
    vector<int> s = find_mod_0_n_subset(v);
    cout<<"results sub-array: "<<endl;
    for(int &e: s)
        cout<<e<<" ";
    cout<<endl;
}

vector<int> find_mod_0_n_subset(vector<int> & a)
{
    vector<int> prefix_array(a);

    for(int i=0;i<a.size();i++)
    {
        prefix_array[i] += i>0? prefix_array[i-1]:0;
        prefix_array[i] %= a.size();
    }

    vector<int> table(a.size(), -1);

    for(int i=0;i<a.size();i++)
    {

        if(prefix_array[i] == 0)
        {
            vector<int> ans(i+1);
            iota(ans.begin(),ans.end(),0);
            return ans;
        }
        else if(table[prefix_array[i]] != -1)
        {
            vector<int> ans(i-table[prefix_array[i]]);
            iota(ans.begin(),ans.end(),table[prefix_array[i]]+1);
            return ans;
        }

        table[prefix_array[i]] = i;
    }
}


