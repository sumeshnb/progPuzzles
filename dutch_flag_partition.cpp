#include<iostream>
#include<vector>
#include<fstream>
using namespace std;


void partition(vector<int> &A, int index);
void swap(int &, int &);

int main()
{
    ifstream infile("numbers.txt");

    vector<int> A;

    int n;
    while( infile >> n)
        A.push_back(n);

    for(int &i: A)
        cout<<i<<" ";
    cout<<endl;
    cout<<"enter the pivot index"<<endl;
    int i;
    cin>>i;
    partition(A,i);

    cout<<"after re-arrange :"<<endl;
    for(int &k: A)
        cout<<k<<" ";
    cout<<endl;

    return 0;
}

void partition(vector<int> &A, int index)
{
    int pivot = A[index];

    int size = A.size();

    int smaller=0,equal=0,larger= size-1;

    while(equal <= larger)
    {
        if(A[equal] < pivot)
        {
            swap(A[smaller++],A[equal++]);
        }else if(A[equal] == pivot)
        {
            equal++;
        }else
        {
            swap(A[equal], A[larger--]);
        }
    }
    /*for(int &k: A)
        cout<<k<<" ";
    cout<<endl; */


}

void swap(int &a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
