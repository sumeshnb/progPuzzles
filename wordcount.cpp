//
// Created by sumesh on 12/24/2015.
//

#include <map>
#include <iostream>
#include <fstream>

using namespace std;

int main(){

    try {
        ifstream in("largefile.txt");

        ofstream out("wordcount.txt");

        map<string,int> wordcount;

        for(string str;in>>str;){
            wordcount[str]++;
        }

        for(auto &p: wordcount){
            cout<<p.first<<" "<<p.second<<"\n";
        }
    }catch (std::exception & e){
        cout<<"file not found exception"<<endl;
    }
    return 0;
}
