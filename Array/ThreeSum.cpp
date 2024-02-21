#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class ThreeSum {
public:
    // Function to find unique triplets that sum to zero
    vector<vector<int>> threeSum(vector<int>& arr) {
        if (arr.empty() || arr.size() < 3) {
            return {};
        }

        sort(arr.begin(), arr.end());
        unordered_set<vector<int>> result;

        // Fix the first element and find the other two elements
        for (int i = 0; i < arr.size() - 2; i++) {
            int left = i + 1;
            int right = arr.size() - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == 0) {
                    // Add the triplet to the result and move to find other triplets
                    result.insert({arr[i], arr[left], arr[right]});
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return vector<vector<int>>(result.begin(), result.end());
    }
};

int main() {
    ThreeSum threeSumObject;
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    
    // Example input
    cout << "Input array: [ ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "]\n";

    // Find three sum combinations
    vector<vector<int>> result = threeSumObject.threeSum(arr);

    // Print the three sum combinations
    cout << "The three sum combinations are: " << "\n";
    for (const auto& triplet : result) {
        cout << "[ ";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "] ";
    }

    return 0;
}
