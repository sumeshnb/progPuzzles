#include<iostream>
using namespace std;

unsigned long swap_bits(unsigned long a, unsigned int i, unsigned int j);

int main()
{
    cout<<"Enter the number "<<endl;
    unsigned long a = 0;
    cin>>a;

    cout<<"enter i"<<endl;

    unsigned int i;
    cin>>i;
    cout<<"enter j"<<endl;

    unsigned int j;
    cin>>j;

    cin>>a;

    cout<<swap_bits(a,i,j)<<endl;

}

unsigned long swap_bits(unsigned long a, unsigned int i, unsigned int j)
{
    //check if the bits at i and j are equal

    if( ((a >> i) & 1L) != ((a >> j) & 1L ))
    {
       a ^= (1L << i) | (1L << j);
    }

    return a;
}

