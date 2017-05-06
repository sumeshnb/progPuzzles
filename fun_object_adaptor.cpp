#include<algorithm>
#include<cstddef>
#include<functional>
#include<iostream>
#include<iterator>

using namespace std;

int main()
{
    int a[]= {1, 2,4, 5,34,56,15};
    const int SIZE = sizeof a/sizeof a[0];
    std::remove_copy_if(a,a+SIZE,ostream_iterator<int>(cout,"\n"),bind2nd(greater<int>(),15));
    return 0;
}

