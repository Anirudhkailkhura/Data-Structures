#include <bits/stdc++.h>
using namespace std;

void helper(int pos, string &str, vector<string> &ans)
{
    // when we have traversed the entire str, then we should put str into ans[]
    if (pos >= str.size())
    {
        ans.push_back(str);
    }

    // Iterating from currentposition till size of str and trying to generate all possible Permutations
    for (int i = pos; i < str.size(); i++)
    {
        // swapping the ith element with the current element
        swap(str[pos], str[i]);

        // ask recursion to do the remaining task
        helper(pos + 1, str, ans);

        // backtrack & undo the changes
        swap(str[pos], str[i]);
    }
}
vector<string> generatePermutations(string &str)
{
    // to keep the final result in store
    vector<string> ans;

    helper(0, str, ans);

    // Specific to this problem because we want the strings sorted in lexicographical order
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string input = "ABC";
    vector<string> result = generatePermutations(input);

    // Print the generated permutations
    for (const string &perm : result)
    {
        cout << perm << " ";
    }

    return 0;
}

// generatePermutations("ABC")
// │
// └── helper(0, "ABC", [])
//     ├── helper(1, "ABC", [])
//     │   ├── helper(2, "ABC", [])
//     │   │   ├── helper(3, "ABC", ["ABC"])
//     │   │   └── helper(3, "ACB", ["ABC"])
//     │   └── helper(2, "BAC", ["ABC", "ACB"])
//     │       ├── helper(3, "BAC", ["ABC", "ACB", "BAC"])
//     │       └── helper(3, "BCA", ["ABC", "ACB", "BAC"])
//     └── helper(1, "BAC", ["ABC", "ACB", "BAC", "BCA"])
//         ├── helper(2, "BAC", ["ABC", "ACB", "BAC", "BCA", "CBA"])
//         │   ├── helper(3, "CBA", ["ABC", "ACB", "BAC", "BCA", "CBA"])
//         │   └── helper(3, "CAB", ["ABC", "ACB", "BAC", "BCA", "CBA"])
//         └── helper(2, "CAB", ["ABC", "ACB", "BAC", "BCA", "CBA", "CAB"])
//             ├── helper(3, "CAB", ["ABC", "ACB", "BAC", "BCA", "CBA", "CAB", "CAB"])
//             └── helper(3, "CBA", ["ABC", "ACB", "BAC", "BCA", "CBA", "CAB", "CAB"])
