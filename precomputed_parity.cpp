#include<iostream>
using namespace std;

#define PRE_COMP_SIZE 65536

int pre_comp_parity[PRE_COMP_SIZE];

void pre_compute(int a[],unsigned int size);
unsigned int parity(unsigned long a);

int main()
{
    cout<<PRE_COMP_SIZE<<endl;

    //pre-compute the parity of all 16 bit numbers
    pre_compute(pre_comp_parity, PRE_COMP_SIZE);
    cout<<"Enter the number: "<<endl;
    unsigned long a = 0;
    cin>>a;
    cout<<parity(a)<<endl;
}


//compute the parity of each 16-bit blocks
//separately and then add all together to 
//get the parity of the input number
unsigned int parity(unsigned long a)
{
    return pre_comp_parity[a>>48] +
        pre_comp_parity[(a>>32) & 0xffff] +
        pre_comp_parity[(a>>16) & 0xffff] +
        pre_comp_parity[a & 0xffff];
}


//Kernighan's method of computing setbits
void pre_compute(int a[], unsigned int size)
{
    //unsigned int size = sizeof(a)/sizeof(a[0]);

    for(int i=0;i<size;i++)
    {
        int value = i;
        int count = 0;
        while(value)
        {
            count++;
            value &= (value-1);
        }
        a[i] = count;
    }
}


