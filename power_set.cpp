#include<iostream>
#include<cmath>
#include<vector>

using namespace std;


void generate_power_set(const vector<unsigned int> &s);

int main()
{
	cout<<"enter the number of numbers"<<endl;
	unsigned int count;
	cin>>count;
	cout <<"enter the elements in the set now"<<endl;

	vector<unsigned int> s;

	unsigned int temp;
	while(count--){
		cin>>temp;
		s.push_back(temp);
	}
	generate_power_set(s);
	return 0;
}

void generate_power_set(const vector<unsigned int> &s){
	for(unsigned int i = 1; i < (1 << s.size()); i++){
		int x = i;
		while(x){
			int index = log2(x & !(x-1));
			cout<<s[index];
			if(x &= (x-1)){
				cout<<",";
			}
		}
		cout<<endl;
	}
}
	


