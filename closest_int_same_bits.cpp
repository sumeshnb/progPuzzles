#include<iostream>
using namespace std;

unsigned long closest_int_same_bits(unsigned long a);
void print_bits(unsigned long a);
int main()
{
    unsigned long a;
    cin>>a;
    cout<<"before change , input value: "<<endl;
    print_bits(a);
    cout<<"after change "<<endl;
    print_bits(closest_int_same_bits(a));
}

unsigned long closest_int_same_bits(unsigned long a){
    //swap the least significant bits which are not equal

    for(unsigned int i=0;i<63;i++){
        if( ((a >> i) & 1L)  ^ ((a >> (i+1)) & 1L)){
            //swap the bits and break from loop
            a ^= (1L<<i) | (1L << (i+1));
            break;
        }
    }

    return a;
}

void print_bits(unsigned long a){
    int j;
    for(unsigned int i=0;i<=63;i++){

        j = 63 - i;

        if((a>>j)  & 1L)
            cout<<"1";
        else
            cout<<"0";
    }
    cout<<endl;
}
