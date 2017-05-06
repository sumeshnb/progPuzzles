#include<iostream>

using namespace std;
int getVal(char c){
    switch(c){
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            cout<<"unexpected character!"<<endl;
            return 0;
    }
}

int main()
{
    //read input
    string str;
    cin>>str;
    //cout<<str;

    bool negative = false;
    int running_total = 0;
    for(int i=0;i<str.length();i++){
        if(i==0 && str[i]=='-')
        {
            negative = true;
            continue;
        }
       running_total = running_total * 10 + getVal(str[i]);
    }
    if(negative)
        running_total*=-1;
    cout<< running_total<<endl;
    return 0;
}
