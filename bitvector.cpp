#include<iostream>
#include<fstream>
#include<cmath>

#define MAX_LIMIT 10000000
#define NO_INTEGERS 100000

using namespace std;

int main()
{
    //get the size of an int
    unsigned int int_size = sizeof(unsigned int);

    //count the number of ints needed in bitvector
    int int_count = (int)(MAX_LIMIT/int_size);

    //increment by 1, if MAX_LIMIT is not a multiple of int_size
    if(MAX_LIMIT % int_size != 0)
    {
        int_count++;
    }

    //now allocate the bitvector and initialize all bits to zero
    unsigned int *bitvector = (unsigned int *)calloc(int_size,int_count);

    //read line by line from input file and flip corresponding bit
    //in bitvector
    ifstream input("random_numbers.txt",ifstream::in);
    ofstream output("output.txt",ofstream::out);

    string line;
    while(std::getline(input,line))
    {
        int current_item = stoi(line);
        //find out the position of current_item in bitvector
        int int_index = floor(current_item/int_size);
        int bit_index = current_item % int_size;
        bitvector[int_index] = bitvector[int_index] | (1 << bit_index);
    }

    //now traverse the bitvector and write sorted numbers to output file
    for(int i=0;i<int_count;i++)
    {
        //print the numbers in current integer index
        unsigned int number = i * int_size;
        //now take care of each bit

        for (unsigned int j=0;j<int_size;j++)
        {
            if( bitvector[i] & (1<<j))
            {
                output<<number+j<<endl;
            }
        }
    }

    cout<<"output written to output.txt file"<<endl;
    free(bitvector);
    return 0;
}
