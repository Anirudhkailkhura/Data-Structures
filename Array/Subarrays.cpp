// Count Subarray sum Equals K

#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the given array.
    int cnt = 0;        // Number of subarrays:

    // i = 0, j = 0:
    // sum = 1, cnt = 0
    // i = 0, j = 1:
    // sum = 1 + 2 = 3, cnt = 0
    // i = 0, j = 2:
    // sum = 3 + 3 = 6, cnt = 0

    for (int i = 0; i < n; i++)
    { // starting index i
        int sum = 0;
        for (int j = i; j < n; j++)
        { // ending index j
            // calculate the sum of subarray [i...j]
            // sum of [i to j-1] + arr[j]
            sum = sum + arr[j];

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}
