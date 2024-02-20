#include <bits/stdc++.h>
using namespace std;

/* Returns the count of subarrays
of arr[] with sum equal to 'sum' */
int subArraySumCount(int arr[], int n, int sum)
{
    int count = 0; // Initialize count of subarrays

    // Pick a starting point
    for (int i = 0; i < n; i++) {
        int currentSum = arr[i];

        if (currentSum == sum) {
            count++; // Increment count for a subarray with the given sum
        } else {
            // Try all subarrays starting with 'i'
            for (int j = i + 1; j < n; j++) {
                currentSum += arr[j];

                if (currentSum == sum) {
                    count++; // Increment count for a subarray with the given sum
                }
            }
        }
    }

    return count;
}

// Driver Code
int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    
    int count = subArraySumCount(arr, n, sum);
    
    if (count > 0) {
        cout << "Count of subarrays with sum " << sum << ": " << count << endl;
    } else {
        cout << "No subarray found with the given sum." << endl;
    }

    return 0;
}
n 