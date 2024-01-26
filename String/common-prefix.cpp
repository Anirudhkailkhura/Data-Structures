#include <bits/stdc++.h>
using namespace std;

// Function to find the common prefix among a vector of strings
string CommonPrefix(vector<string> &str) {
    // Sort the strings lexicographically
    sort(str.begin(), str.end());

    string str1 = str[0];
    int i = 0;
    string str2 = str[str.size() - 1];
    int j = 0;

    string ans = "";

    // Compare characters of the first and last strings
    while (i < str1.size() && j < str2.size()) {
        if (str1[i] == str2[j]) {
            ans += str1[i];
            i++;
            j++;
        } else {
            break;
        }
    }

    return ans;
}

int main() {
    // Input a vector of strings
    vector<string> strings;
    int n;
    
    cout << "Enter the number of strings: ";
    cin >> n;

    cout << "Enter the strings: ";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strings.push_back(s);
    }

    // Find and print the common prefix
    string commonPrefix = CommonPrefix(strings);
    cout << "Common Prefix: " << commonPrefix << endl;

    return 0;
}
