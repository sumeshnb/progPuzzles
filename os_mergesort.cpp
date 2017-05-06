#include<iostream>

using namespace std;

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"
#defien INPUT_SIZE 100000

int main()
{
    cout<<"sorting begins!"<<endl;

    int a[INPUT_SIZE];
    ifstream input(INPUT_FILE,ifstream::in);
    ofstream output(OUTPUT_FILE,ofstream::out);

    //read entries from file and populate array
    string line;
    int i=0;
    while(std::readline(input,line))
    {
        a[i++] = stoi(line);
    }

    //now sort the elements
    merge_sort(a,0,INPUT_SIZE - 1);

    //write the array output to file
}


void merge_sort(int a[],int begin,int end)
{
    int input_size = end - begin + 1;
    if(input_size <=1)
        return;

    //call merge_sort on two equal halves of the input array

    int middle;
    if(input_size % 2 == 0){
       middle = (begin+end)/2
    }else{
        middle = floor((begin+end)/2);
    }

    merge_sort(a,begin,middle);
    merge_sort(a,middle+1,end);
    merge(a,begin,end)
}

void merge(int a[],int begin,int end)
{

    int input_size = end - begin + 1;
    int middle;
    if(input_size % 2 == 0){
        middle = (begin+end)/2
    }else{
        middle = floor((begin+end)/2);
    }

    int i=begin;//index for first half
    int j=middle;//index for second half
    int k=begin;//index for the result
    int window_size = 0;
    int window_index = middle;

    for(k=begin;k<=end;k++)
    {
        if(a[i] <= a[j])
        {
            i++;
        }else
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            window_size++;
            i++;
            j++;
        }
    }
}
