#include <vector>
#include <iostream>

using namespace std;

// Function to perform Bubble Sort on a vector of integers
void bubbleSort(vector<int> &v) {
    int n = v.size();

    // Outer loop for each pass through the array
    for (int i = 0; i < n - 1; i++) {
        // Inner loop for comparing and swapping adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            // If the current element is greater than the next element, swap them
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
    // Sorting is complete
    return;
}

int main() {
    // Input the number of elements in the vector
    int n;
    cin >> n;

    // Input the elements of the vector
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Call the Bubble Sort function to sort the vector
    bubbleSort(v);

    // Output the sorted vector
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
