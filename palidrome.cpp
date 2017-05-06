#include<iostream>
#include<string>
#include<cctype>

using namespace std;

bool isPalidrome(string str);

int main(){
    cout<<"enter input string"<<endl;
    string str;
    cin>>str;
    cout<<isPalidrome(str)<<endl;
    return 0;
}

bool isPalidrome(string str)
{
    string::iterator fitr = str.begin();
    string::iterator bitr = str.end();

    --bitr;//place the iterator pointing to last char

    while(fitr != bitr){
        if(!isalnum(*fitr)){
            fitr++;
            continue;
        }

        if(!isalnum(*bitr)){
            bitr--;
            continue;
        }

        if(*fitr++ != *bitr--){
            return false;
        }
    }
    return true;
}
