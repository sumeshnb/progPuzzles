#include<iostream>
using namespace std;
extern "C" {
	void f(int);
};
int main()
{
	f(2);
	return 0;
}

