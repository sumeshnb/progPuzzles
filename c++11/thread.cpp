#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

static const int num_threads = 10;

std::mutex m;

void call_from_thread(int id){
    std::lock_guard<std::mutex> guard(m);
    cout<<"Thread "<<id<<endl;
}

int main(){
    std::thread t[num_threads];

    for(int i=0;i<num_threads;i++)
        t[i] = std::thread(call_from_thread,i);

    cout<<"Thread: main"<<endl;
        
    //join the thread
    for(int i=0;i<num_threads;i++)
        t[i].join(); 

    return 0;
}
