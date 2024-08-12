#include <bits/stdc++.h>
using namespace std;

int findLargestElement (int arr[] , int n){

    int max = arr[0];
    for(int i = 0; i<n; i++){
        if(max< arr[i]){
            max = arr[i];
        }
    }
    return max;
}


int main()
{

    int arr[] = {1,4,5,3,1};
    int n = 5;
    int max = findLargestElement(arr, n);
    cout<< "the largest element " <<max<<endl;
 return 0;
}