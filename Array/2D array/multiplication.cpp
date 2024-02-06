// multiplication of two matrices

#include <bits/stdc++.h>
using namespace std;
int main()
{
    //input matrixs
    int r1, c1;
    cin > r1 > c1;

    int A[r1][c1] for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
            cin > A[r1][c1];
    }

    int r2, c2;
    cin > r2 > c2;

    int B[r2][c2];
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cin >> B[r2][c2];
        }
    }

    if(c1!= r2){
        cout<<"not possible"<<endl;
    }

    //answer matrix
    int C[r1][c2];  

    for(int i = 0;i< r1;i++){
        for(int j = 0; j<c2;j++){
            int value = 0;
            for(int k = 0; k< r2; k++){
                value+=A[1][k]*B[k][j];
            }
        }
    }



    return 0;
}