/* This question is exactly similar to Permutations - I
Only difference being we have duplicate elements in nums[]. But we need to print Unique Permutations only
For that purpose, we have used a local unordered_set data structure which tells us if that particular element has been previosuly encountered or not
If we have taken / chosen the element before, we will not include it anymore.
But if we haven't included the element, we will include it now
*/
#include <bits/stdc++.h>
using namespace std;

void helper(int pos, int n, vector<int> &nums, vector<vector<int>> &ans)
{
    // Base Case executes when we have traversed the entire nums[]

    if (pos >= n)
    {
        ans.push_back(nums);
        return;
    }

    // Unordered_set ensures we are not taking duplicates and thus not making Duplicate Permutation

    unordered_set<int> set;

    // The rest logic remains exactly the same

    for (int i = pos; i < n; i++)
    {
        // If we have encountered the element before, we will simply skip the rest of iterations

        if (set.find(nums[i]) != set.end())
            continue;

        // We insert nums[i] so that we don't create Duplicate Permutations

        set.insert(nums[i]);

        // We simply use our swapping logic to create Permutations

        swap(nums[pos], nums[i]);

        // Ask recursion to do rest of the task

        helper(pos + 1, n, nums, ans);

        // Backtrack and undo the change we have done

        swap(nums[pos], nums[i]);
    }

    return;
}

vector<int> generatePermutations(vector<int> &nums)
{
    // to keep the final result in store
    vector<int> ans;

    helper(0, nums.size(), nums, ans);

    // Specific to this problem because we want the integers sorted in lexicographical order
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> input = {1, 2, 3};
    vector<int> result = generatePermutations(input);

    // Print the generated permutations
    for (const int &perm : result)
    {
        cout << perm << " ";
    }

    return 0;
}

/*
Time Complexity  = O(N * N!)
Space Complexity = O(N)
*/