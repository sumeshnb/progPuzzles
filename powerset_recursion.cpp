#include<iostream>
#include<vector>
#include<iterator>


using namespace std;

void generate_power_set(const vector<unsigned int> &s);
void generate_power_set_helper(const vector<unsigned int> &s,unsigned int idx,
								 vector<unsigned int> res);

int main()
{
	cout<<"enter the number of numbers"<<endl;
	unsigned int count;
	cin>>count;
	cout <<"enter the elements in the set now"<<endl;

	vector<unsigned int> s;

	unsigned int temp;
	while(count){
		cin>>temp;
		s.push_back(temp);
		count--;
	}
	
	cout<<"Set entered is: ";
	for(int i=0;i<s.size();i++) cout<< s[i]<<" ";
	cout<<endl;
	generate_power_set(s);
}

void generate_power_set(const vector<unsigned int> &s)
{
	vector<unsigned int> res;

	generate_power_set_helper(s,0,res);
}

void generate_power_set_helper(const vector<unsigned int> &s,unsigned int idx,
								 vector<unsigned int> res)
{
	//print all the items in res
	if(res.empty() == false)
	{
		copy(res.cbegin(),res.cend()-1,ostream_iterator<unsigned int>(cout,","));
		cout<<res.back()<<endl;
	}

	for(int i=idx;i<s.size();i++)
	{
		res.emplace_back(s[i]);
		generate_power_set_helper(s,i+1,res);
		res.pop_back();
	}
}
