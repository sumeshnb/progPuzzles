#include<iostream>
#include<string>

using namespace std;
string myItoa(int);

int main(){
    cout<<"enter the number"<<endl;
    int number;
    cin>>number;
    cout<<myItoa(number)<<endl;
    return 0;
}

string myItoa(int number){
    string str;

    bool isNegative = number<0?number=-number,true:false;

    while(number){
        char item = '0'+number%10;
        str.insert(str.begin(),item);
        number /= 10;
    }

    if(isNegative){
        str.insert(str.begin(),'-');
    }
    return str;
}
