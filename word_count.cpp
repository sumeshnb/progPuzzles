#include<map>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream in("all_primes.cpp");
    map<string,int> m;

    for(string str;in>>str;)
        m[str]++;
    for(const auto &i: m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
}
