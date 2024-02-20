// C++ program to count maximum consecutive
// 1's in a binary array.
#include<bits/stdc++.h>
using namespace std;

// Function to get the maximum length of consecutive 1s in a binary array
int getMaxLength(bool arr[], int n)
{
    int count = 0; // Initialize count to 0
    int result = 0; // Initialize the maximum length of consecutive 1s to 0

    // Loop through the array elements
    for (int i = 0; i < n; i++)
    {
        // Reset count to 0 when 0 is found
        if (arr[i] == 0)
            count = 0;
        else
        {
            count++; // Increase count for consecutive 1s
            result = max(result, count); // Update result if count becomes more
        }
    }

    return result; // Return the maximum length of consecutive 1s
}

// Driver code
int main()
{
   
    bool arr[] = {1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Print the result of the function
    cout << "Maximum length of consecutive 1s: " << getMaxLength(arr, n) << endl;

    return 0;
}
