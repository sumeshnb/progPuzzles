#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;

string multiply_bignumbers(string &one, string &two);


int main()
{
    cout<<" Enter two big numbers: "<<endl;
    string one,two;
    cin>>one>>two;

    string answer = multiply_bignumbers(one, two);

    cout<<"Answer : "<<answer<<endl;
}

string multiply_bignumbers(string &one, string &two)
{

    bool positive = true;

    if(one.front() == '-')
    {
        positive = !positive;
        one = one.substr(1);
    }

    if(two.front() == '-')
    {
        positive = !positive;
        two = two.substr(1);
    }

    //let us reverse the strings for more readability
    reverse(one.begin(),one.end());
    reverse(two.begin(),two.end());

    //now we have LSB in the begining of the strings
    //Let us do the grade school multiplication algorithm:-)

    //declare answer string of size m+n
    vector<int> ans(one.size()+two.size()+1,0);

    for(int i=0;i<one.size();i++)
    {
        for(int j=0;j<two.size();j++)
        {
            ans[i+j] += (one[i] - '0')*(two[j] - '0');
            ans[i+j+1] += ans[i+j] / 10;
            ans[i+j] %= 10;
        }
    }


#ifdef DEBUG
    for(int &k: ans)
        cout<<k;
    cout<<endl;
#endif

    //revese the digits and get result
    //
    stringstream ss;
    for(int i=ans.size()-1;i>=0;i--)
    {

        ss<<ans[i];
    }

    //return ss.str();
    return string((positive?"":"-") + ss.str());
}
