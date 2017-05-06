#include<iostream>
using namespace std;
int main(){
    string str;
    //read input string
    std::getline(cin,str);

    //first reverse all characters in the string
    for(int i=0; i<str.length()/2;i++){
        //exchange ith position and length-ith position
        char temp = str[i];
        str[i] = str[str.length() - i-1];//array index begins at zero:-)
        str[str.length() - i-1] = temp;
    }

    //reverse individual words in the string
    int i=0;
    while(i<str.length()){
        int end_of_word = 0;
        //search for white space or null
        for(int j=i+1;j<=str.length();j++){
            if(str[j] == ' ' or str[j] == '\0'){
                end_of_word = j-1;
                break;
            }
        }

        //we have the begining and end of word, reverse the word
        for(int k=i,l=0;k<=(i+end_of_word)/2;k++,l++){
            //exchange kth position and end_of_word-lth position
            char temp = str[k];
            str[k] = str[end_of_word - l];
            str[end_of_word - l] = temp;
        }

        //set i to begining of next word
        i = end_of_word+2;
    }

    cout<<str<<endl;
    return 0;
}
