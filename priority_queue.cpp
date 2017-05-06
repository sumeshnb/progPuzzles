#include<iostream>
#include<queue>

using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(5);
    pq.push(1);
    pq.push(7);
    pq.push(5);

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    return 0;
}
