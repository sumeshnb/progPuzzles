#include<iostream>
#include<algorithm>
#include<cassert>
#include<vector>

using namespace std;

int main()
{
    int a[] = {4,7,1,43,0};
    int SIZE = sizeof(a)/sizeof(a[0]);
    vector<int> v1(a,a+SIZE);
    vector<int> v2(SIZE);
    copy(v1.begin(),v1.end(),v2.begin());
    assert(equal(v1.begin(),v1.end(),v2.begin()));
    cout<<"worked fine"<<endl;
    return 0;
}
