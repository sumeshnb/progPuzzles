#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

int main()
{
    std::ifstream input("input.txt", std::ifstream::in);
    std::ofstream output("output.txt", std::ifstream::out);
    std::vector<int> varray;

    std::string line;
    while(std::getline(input,line))
    {
        int number = std::stoi(line);
        varray.push_back(number);
    }

    //now sort the array
    std::sort(varray.begin(),varray.end());

    for(std::vector<int>::iterator it = varray.begin();it != varray.end();++it)
    {
        output << *it<<std::endl; 
    }

    input.close();
    output.close();

    std::cout<<"sorted output is written to file output.txt"<<std::endl;
    return 0;
}
