#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to check if two strings are isomorphic
bool isIsomorphic(string s1, string s2) {
    // Arrays to store the last seen positions of characters in the strings
    vector<int> v1(128, -1); // For characters in s1
    vector<int> v2(128, -1); // For characters in s2

    // If the lengths of the strings are different, they cannot be isomorphic
    if (s1.size() != s2.size()) {
        return false;
    }

    // Loop through each character in the strings
    for (int i = 0; i < s1.size(); i++) {
        // Check if the last seen positions of the characters in both strings are different
        if (v1[s1[i]] != v2[s2[i]]) {
            return false; // If different, strings are not isomorphic
        }

        // Update the last seen positions of the characters in both strings
        v1[s1[i]] = v2[s2[i]] = i;
    }

    return true; // If the loop completes, the strings are isomorphic
}

int main() {
    string s1, s2;

    // Input two strings
    cout << "Enter the first string: ";
    cin >> s1;

    cout << "Enter the second string: ";
    cin >> s2;

    // Check if the strings are isomorphic and print the result
    if (isIsomorphic(s1, s2)) {
        cout << "Yes, the strings are isomorphic." << endl;
    } else {
        cout << "No, the strings are not isomorphic." << endl;
    }

    return 0;
}
