#include<iostream>
#include<fstream>
#include<ctime>
#define N 10000000
#define K 1000000

using namespace std;

int a[N];

void swap(int i,int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

//returns a random number between i and j
int random(int i, int j)
{
    return rand() % (j-i) + i;
}

int main()
{
    //initialize random seed
    srand(time(NULL));

    //initialize array with numbers from 0....n range
    for(int i=0;i<N;i++)
        a[i]=i;

    ofstream output("random_numbers.txt",ofstream::out);
    for(int i=0;i<K;i++)
    {
        swap(i, random(i,N-1));
        output<<a[i]<<endl;
    }
    cout<<"Done"<<endl;
    output.close();
    return 0;
}
