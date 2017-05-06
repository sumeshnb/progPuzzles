#include<iostream>
#include<algorithm>
#include<cassert>

using namespace std;
bool gt6(int a){
    return a>6;
}
int main()
{
    int a[] = { 6,4,7,1,7};
    const size_t SIZE = sizeof(a)/sizeof(a[0]);
    int b[SIZE];
    replace_copy_if(a,a+SIZE,b,gt6,7);
    assert(equal(a,a+SIZE,b));
    cout<<"Bye"<<endl;
    return 0;
}
