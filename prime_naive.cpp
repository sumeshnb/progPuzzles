#include<iostream>
#include<cmath>
using namespace std;
bool is_prime(unsigned int a);
int main()
{
	unsigned int a;
	cin>>a;
	const char *str = is_prime(a)?"Yes,prime!":"No, not prime";
	cout<<str<<endl;

}

bool is_prime(unsigned int a)
{
	//check all the numbers in the range 2 to root(n)

	for(int i=2;i<=sqrt(a);i++)
	{
		if(a%i == 0)
			return false;
	}
	return true;
}
