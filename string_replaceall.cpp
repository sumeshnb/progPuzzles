#include<iostream>
#include<string>

using namespace std;
void replace_all(string &base,string &from,string &to);
int main()
{
	cout<<"enter the base string"<<endl;
	string base;
	std::getline(cin,base);
	cout<<"enter from"<<endl;
	string from;
	std::getline(cin,from);
	cout<<"enter to"<<endl;
	string to;
	std::getline(cin,to);
	
	replace_all(base,from,to);

	cout<<"modified string is: "<<endl;
	cout<<base<<endl;
}

void replace_all(string &base,string &from,string &to){
	size_t position=0;
	size_t location_found=0;

	while((location_found = base.find(from,position)) != string::npos){
		base.replace(location_found,from.size(),to);
		cout<<base<<endl;
		position = location_found + to.size();
	}
}
