//For a boolean 2-D array where each row is sorted, find the row with a maximum number of 1s.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxcount = 0;
        int index = 0;

        // Iterate through each row of the matrix
        for (int i = 0; i < mat.size(); i++) {
            int countone = 0;

            // Iterate through each column of the current row
            for (int j = 0; j < mat[i].size(); j++) {
                // If the element is 1, increment countone
                if (mat[i][j] == 1) {
                    countone++;
                }
            }

            // Update maxcount and index if the current row has more ones
            if (countone > maxcount) {
                maxcount = countone;
                index = i;
            }
        }

        // Return a vector containing the index and maxcount
        return {index, maxcount};
    }
};

int main() {
    // Example usage
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 1}
    };

    Solution solution;
    vector<int> result = solution.rowAndMaximumOnes(matrix);

    // Output the result
    cout << "Row index with maximum ones: " << result[0] << endl;
    cout << "Count of ones in that row: " << result[1] << endl;

    return 0;
}
