#include<iostream>

using namespace std;

int main()
{
    copy(istream_iterator<int>(cin),istream_iterator<int>(),ostream_iterator<int>(cout,"\n"));
}
