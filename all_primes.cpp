#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
vector<unsigned int> generate_all_primes(unsigned int a);

int main()
{
	cout<<"enter the number"<<endl;

	unsigned int a;
	cin>>a;
	vector<unsigned int> primes = generate_all_primes(a);

	cout<<"just before printing"<<endl;

	for(unsigned int &a: primes)
		cout<<a<<endl;
}

vector<unsigned int> generate_all_primes(unsigned int a)
{
	vector<unsigned int> primes;

	//calculate the size of bit vector needed
	//we are not going mark any even number as not prime
	//we exclude all even integers
	//also, storage not needed for 0,1 and 2
	int size = floor(0.5*(a-3))+1;
	vector<bool> bit_vector_isprime(size,true);

	for(int i=0;i<size;i++){
		if(bit_vector_isprime[i]){
			unsigned int p = 2*i+3;
			primes.emplace_back(p);
			//also mark all multiples of 2*i+3 as not prime in bit vector
			for(int k=i+p;k<size;k+=p)
				bit_vector_isprime[k]= false;
		}
	}
	return primes;
}
