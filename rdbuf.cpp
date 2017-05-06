#include<fstream>
#include<iostream>

using namespace std;

int main()
{
  ifstream f("atoi.cpp");
  cout<<f.rdbuf();
}
