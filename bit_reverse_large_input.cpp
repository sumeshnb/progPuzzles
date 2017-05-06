#include<iostream>

using namespace std;

#define SIZE 1L<<16
#define WORD_SIZE 64

unsigned long pre_comp[SIZE];
void precompute();
unsigned long reverse_bits(unsigned long a);

//this program is written for 64bit input numbers
int main()
{
    precompute();
    unsigned long a;
    cout<<" enter the number"<<endl;
    cin>>a;
    cout<<reverse_bits(a)<<endl;
}

unsigned long reverse_bits(unsigned long a){
    return pre_comp[ (a >> 48) & 0xffff] |
        pre_comp[ ((a >> 32) & 0xffff)] << 16 |
        pre_comp[ ((a >> 16) & 0xffff)] << 32 |
        pre_comp[ ( a & 0xffff)] << 48 ;
}

//precompute "reverse bits" for each int
//that can be represented by 16 bits
void precompute()
{
    for(unsigned int k=0;k<SIZE;k++)//loop for each number from 0 to 65535
    {
        unsigned int value = k;
        for(int i=0,j=16-1;i<16/2;i++,j--)
        {
            //swap bits i and j in value 
            if( (k>>i & 1L) != ((k>>j) & 1L))//check if ith and jth bits are equal
            {
                //swap bits
                value ^= ((1L<<i) | (1L<<j));
            }
        }
        //now value has reversed bits of k
        pre_comp[k] = value;
    }
}
