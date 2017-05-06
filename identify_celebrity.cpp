#include<string>
#include<vector>
#include<fstream>
#include<deque>
#include<iostream>
#include<sstream>

using namespace std;

int findCelebrity(vector<deque<bool>> &A);
int main()
{ 
    //read the contents from file and 
    //create a vector of deque<bool> s
    ifstream in("identify_celebrity.txt");
    string line;
    vector<deque<bool>> input_matrix;
    while(std::getline(in,line)){
        deque<bool> current_row;
        istringstream ss(line);

        bool i;
        while(ss>>i){
            current_row.push_back(i);
        }
        input_matrix.push_back(current_row);
    }

#ifdef DEBUG
    for(auto &row: input_matrix){
        for(auto &column: row){
            cout<<column<<" ";
        }
        cout<<'\n';
    }
#endif
    cout<<"celebrity is :"<<findCelebrity(input_matrix)<<endl;
    return 0;
}

int findCelebrity(vector<deque<bool>> &A){
    int i=0,j=1;
    while(j<A.size()){
        if(A[i][j]){
            i = j++;//set i to j, and j to j++
            //according to the problem , the celebrity knows no one
            //if A[i][j] = true means, i is not a celebrity,
            //also we know that all those less than j are not celebrities
        }
        else{
            //all people < j are not celebrities
            ++j;
        }
    }
    return i;
}
