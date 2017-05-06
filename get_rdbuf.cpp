#include<iostream>
#include<fstream>
using namespace std;
int main()
{
  ifstream f("rdbuf.cpp");
  while(f.get(*cout.rdbuf()))
      f.ignore();
}
