/*
 * You are given a vector<vector<int>>
 * each inner vector has a set of integers, 
 * which are sorted in non decreasing order
 * your task is to create a single vector<int> which
 * will contain the union of all the elements in the 
 * input vector given
 * eg input :
 * {-5, 2, 8, 9,10}
 * {-4,2,7,8}
 * {1,2}
 * {4,7}
 * expected output is:
 * {-5,-4,1,2,4,7,8,9,10}
 */


#include<iostream>
#include<vector>

using namespace std;

int main(){

    //provide input here
    vector<vector<int>> v{{-5,2,8,9,10},{-4,2,7,8},{1,2},{4,7}};

    cout<<"input provided is:"<<endl;
    for(auto &a:v){
	for(auto &b:a){
	    cout<<b<<" ";
	}
	cout<<endl;
    }

    vector<int> u = union_find(v);
    
    //print output
    for(auto i:u){
	cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

vector<int> union_find(vector<vector<int>> &v){

    size_t size = v.size();
    if(size < 1)
	return vector<int>{};

    decltype(v[0].begin()) arr[] = new arr;

    //array of iterators
    for(auto &a: v){
	arr[i] = a.begin();
    }
    

}

