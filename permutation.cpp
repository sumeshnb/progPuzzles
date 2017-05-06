#include<iostream>
#include<string>

using namespace std;

void permutations(string&);
void permutationsHelper(string str,int fixedPos);

int main(){
    cout<<"enter the string"<<endl;
    string str;
    cin>>str;
    permutations(str);
    return 0;
}

void permutations(string &str){
    permutationsHelper(str,0);
}

void permutationsHelper(string str,int fixedPos){

    if(fixedPos == str.size() -1){
        //we reached leaf node
        cout<<str<<endl;
        return;
    }

    for(int i=fixedPos;i<str.size();i++){
        //exhange each position with fixed pos
        string str1(str);
        char temp = str1[fixedPos];
        str1[fixedPos] = str1[i];
        str1[i] = temp;
        permutationsHelper(str1,fixedPos+1);
    }
}

