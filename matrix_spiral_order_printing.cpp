#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void printMatrixInSpiralOrder(vector<vector<int>> &A);
void printMatrixClockwise(vector<vector<int>> & A, int offset);

int main()
{
    //assumption : we gonna deal with square matrix

    //read dimension
    int i;
    cin>>i;

    cout<<"enter elements line by line, each line end with a nonnum character"<<endl;

    vector<vector<int>> matrix;
    while(i--){
        int k;
        vector<int> *row = new vector<int>();
        while(cin>>k)
            row->emplace_back(k);
        cin.clear();
        cin.ignore(1);
        matrix.push_back(*row);
    }

#ifdef DEBUG
    for(auto &v: matrix){
        for(auto &a: v){
            cout<<a<<" ";
        }
        cout<<endl;
    }
#endif

    printMatrixInSpiralOrder(matrix);

    return 0;

}
void printMatrixInSpiralOrder(vector<vector<int>> &A){
    for(int offset=0; offset < ceil(0.5 * A.size()); ++offset){
        printMatrixClockwise(A, offset);
    }
}

void printMatrixClockwise(vector<vector<int>> & A, int offset){
    if(offset == A.size() - offset -1){
        //we are at the center of an odd dimension matrix
        cout<<A[offset][offset];
    }

    //print the walls of the sub-matrix in clockwise

    //top wall of the matrix
    for(int i=offset,j=offset;j<A.size()-offset-1;j++)
        cout<<A[i][j]<<" ";

    //right wall of the matrix
    for(int i=offset,j=A.size()-offset-1;i<A.size()-offset-1;i++)
        cout<<A[i][j]<<" ";

    //bottom wall of the matrix
    for(int i=A.size()-offset-1,j=A.size()-offset-1;j>offset;j--)
        cout<<A[i][j]<<" ";

    //left wall of the matrix
    for(int i=A.size()-offset-1,j=offset;i>offset;i--)
        cout<<A[i][j]<<" ";
}

        



















