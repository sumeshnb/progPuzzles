#include<iostream>
#include<cstdlib>

int main()
{
    int array[100];
    std::generate_n(array,100,rand);
    std::copy(array,array+100,std::ostream_iterator<int>(std::cout,"\n"));
    return 0;
}
