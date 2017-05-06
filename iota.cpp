#include<iostream>
#include<numeric>
#include<vector>

int main()
{
    std::vector<int> v(10);
    std::iota(v.begin(),v.end(),100);
    for(int &i: v)
        std::cout<<i<<std::endl;

    return 0;
}
