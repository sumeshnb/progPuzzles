#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(){
	string r_str = R"((\+|-)?[[:digit:]]+)";
	regex integer(r_str);
	string input;
	cout<<"enter an integer"<<endl;
	cin>>input;
	if(regex_match(input,integer)){
		cout<<"good! its an integer"<<endl;
	}
	else{
		cout<<"bad! its not an integer"<<endl;
	}
}