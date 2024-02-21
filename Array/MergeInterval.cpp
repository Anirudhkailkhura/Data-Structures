#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    // sort the given intervals in ascending order based on start points:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans; // vector to store merged intervals

    for (int i = 0; i < n; i++) { // iterate through each interval
        int start = arr[i][0];
        int end = arr[i][1];

        // Skip all the merged intervals:
        if (!ans.empty() && end <= ans.back()[1]) {
            // If the current interval is completely contained within the last merged interval, skip it.
            continue;
        }

        // check the rest of the intervals for overlapping:
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                // If there is an overlap, update the end point to the maximum of the two intervals.
                end = max(end, arr[j][1]);
            } else {
                // If no overlap, break out of the inner loop.
                break;
            }
        }

        // Add the merged interval to the result vector.
        ans.push_back({start, end});
    }

    return ans; // return the vector of merged intervals
}

int main() {
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);

    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}
