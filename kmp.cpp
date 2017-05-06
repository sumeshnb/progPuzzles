#include<iostream>
#include<string>
#include<vector>

using namespace std;

void kmp(const string & text, const string &pattern);
vector<int> computePrefix(const string &p);

int main(){
    cout<<"enter text"<<endl;
    string text;
    cin>>text;
    cout<<"enter pattern"<<endl;
    string pattern;
    cin>>pattern;
    kmp(text,pattern);
    return 0;
}


void kmp(const string & text, const string &pattern){
    int n = text.length();
    int m = pattern.length();
    vector<int> pi = computePrefix(pattern);
    //pi.erase(pi.begin());
    cout<<"PI size: "<<pi.size()<<endl;

#ifdef DEBUG
    for(auto &k: pi)
        cout<<k;
    cout<<endl;
#endif

    int q = 0;//number of characters matched so far

    for(int i=0;i<n;i++){// iterate over each char of text

        while(q>0 && pattern[q] != text[i]){
            q = pi[q];
        }
        if(pattern[q] == text[i]){
            q++;
        }
        if(q == m-1){
            cout<<"pattern found at location :"<<i-m+1<<endl;
            q = pi[q];
        }
    }
}

vector<int> computePrefix(const string &p){
    int q = p.size();
    int k = 0;
    vector<int> pi(q,0);//length = q, each element initialize to zero
    pi[0] = 0;

    for(int i=1;i<q;i++){
        while(k>0 && p[k+1] != p[i]){
            k = pi[k];//because of zero based index
        }
        if(p[k+1] == p[i]){
            k++;
        }
        pi[i] = k;
    }
    return pi;
}
