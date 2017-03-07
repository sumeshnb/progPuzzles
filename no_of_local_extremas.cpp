// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<climits>
int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)

    int previous_min = INT_MIN;
    int previous_max = INT_MAX;

    bool min_range_started = false;
    bool max_range_started = false;

    int previous_item = 0;

    int mincount = 0;
    int maxcount = 0;

    bool flag = true;

    for(auto &a: A){

        if(!min_range_started){
            if(previous_max > a){
                min_range_started = true;
            }
        }

        if(!max_range_started){
            if(previous_min < a){
                max_range_started = true;
            }
        }


        //special handling of first element
        if(flag){
            flag = false;
            continue;
        }

        if(a == previous_item){
            continue;
        }

        if(a > previous_item){
            if(min_range_started){
                mincount++;
                min_range_started = false;
                previous_max = a;
            }
            else{
                previous_max=a;
            }
        }
        else{
            min_range_started = true;
            previous_max = previous_item;
        }

        if(a < previous_item){
            if(max_range_started){
                maxcount++;
                max_range_started = false;
                previous_min = a;
            }
        }
        else{
            max_range_started = true;
            previous_min = previous_item;
        }

        previous_item = a;
    }
    
    //handle last element separately
    
    if(max_range_started)
        maxcount++;
    if(min_range_started)
        mincount++;
    
    
     return mincount+maxcount;
}

