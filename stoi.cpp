#include<iostream>
#include<string>

using namespace std;

int newStoi(string str);

int main(){
    cout<<"enter the string"<<endl;
    string str;
    cin>>str;
    cout<<newStoi(str)<<endl;
    return 0;
}

int newStoi(string str){

    int number=0;
    bool isNegative = false;

    for(int i=0;i<str.size();i++){
        if(i == 0 && str[i] == '-'){
            isNegative = true;
            continue;
        }else{
            number = number*10+str[i]-'0';
        }
    }
    return isNegative? -number:number;
}
