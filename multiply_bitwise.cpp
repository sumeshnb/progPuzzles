#include<iostream>
using namespace std;

unsigned multiply_no_operators(unsigned a, unsigned b);
unsigned add_no_operator(unsigned a, unsigned b);
int main()
{
	unsigned int a,b;
	cin>>a;
	cin>>b;
	cout<<multiply_no_operators(a,b)<<endl;
}

unsigned multiply_no_operators(unsigned a, unsigned b){
	unsigned k=1,sum=0,shifted_b=b;

	while(k){
		if(a & k){
			sum = add_no_operator(sum,shifted_b);
		}
		k <<= 1;
		shifted_b <<= 1;
	}

	return sum;
}

unsigned add_no_operator(unsigned a, unsigned b){
	unsigned k=1,sum=0,carryin=0;

	while(k){
		unsigned ak = a&k,bk = b&k;
		unsigned carryout = ak & bk | ak & carryin | bk & carryin;
		sum |= (ak ^ bk ^ carryin);
		carryin = carryout << 1;
		k <<= 1;
	}

	return sum;
}
