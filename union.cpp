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

    using it_type = decltype(v[0].begin());
    vector<pair<it_type,it_type>> it_v; 

    //array of iterators
    for(auto &a: v){
	it_v.push_back(a.begin(),a.end());
    }

    bool loop_flag = true;

    //result vector
    vector<int> target;

    while(loop_flag){

	int min = INT_MAX;

	for(auto &p: it_v){
	    if(p.first != p.second){//process only if this vector is not finished
		if(*p.first == min){
		    ++p.first;//skip the item, its a duplicate
		}
		else if(*p < min){
		    min = *p;
		    ++p;
		}
		else{
		    ;//do nothing
		}

	    }
	}

    }

}

