#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    ifstream input("test.txt",ifstream::in);

    string str;
    while(input >> str)
        cout<<str<<endl;
}
