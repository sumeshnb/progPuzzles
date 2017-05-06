#include<iostream>
#include<random>
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<thread>

using namespace std;

vector<string> ReservoirSampling(ifstream &istr, int k);
int main()
{
    //read from a very large file and 
    //consider each word as a pcket:-)
    ifstream in("largefile.txt",ios::in);
    //read k
    int k;
    cin>>k;
    vector<string> v = ReservoirSampling(in, k);
    //print the results
    for(string &str: v)
        cout<<str<<endl;;
    cout<<endl;
    return 0;
}

vector<string> ReservoirSampling(ifstream &istr, int k){

    vector<string> R;
    string x;
    for(int i = 0;i<k && istr>>x;++i)
    {
        R.emplace_back(x);
    }

    int element_no = k;
    while(istr >> x ){
        //this_thread::sleep_for (chrono::seconds(1));
        std::random_device rd;
        default_random_engine gen( rd());

        //create a random int in [0, no_of_elements]
        uniform_int_distribution<int> dis(0, element_no++);
        int tar = dis(gen);
        if(tar < k){
            R[tar] = x;
        }
    }
    cout<<R.size()<<endl;
    this_thread::sleep_for (chrono::seconds(4));
    return R;
}
