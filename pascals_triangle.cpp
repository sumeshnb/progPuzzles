#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout<<"enter no of lines in Pascal's triangle"<<endl;
    int n;
    cin>>n;
    vector<vector<int>> printTriangle(int n);
    vector<vector<int>> res=printTriangle(n);
    for(auto &v: res){
        for(auto &a: v){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return 0;
}

vector<vector<int>> printTriangle(int n)
{
    if(n<1){
        return {};
    }
    vector<vector<int>> result;
    result.emplace_back(vector<int>{1});
    for(int i=1;i<n;++i){
        vector<int> current_row{1};
        for(int j=1;j<i;++j){
            current_row.emplace_back(result.back()[j-1] + result.back()[j]);
        }
        current_row.emplace_back(1);
        result.emplace_back(current_row);
    }
    return result;
}
