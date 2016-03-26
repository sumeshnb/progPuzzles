#include<map>
#include<iostream>
#include<string>

using namespace std;

int main(){
    multimap<string,int> mm = {{"apple",2},{"pear",2},{"apple",7},{"orange",2},{"apple",9}};
    const string k="apple";

    auto pp = mm.equal_range(k);

    if(pp.first == pp.second)
        cout<<"no element with value="<<k<<endl;
    else{
        for(auto p=pp.first;p!=pp.second;++p)
            cout<<p->second<<' ';
    }

    return 0;
}
