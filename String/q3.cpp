#include <bits/stdc++.h>
using namespace std;

// Function to check if two strings are anagrams
bool anagram(string s1, string s2) {
    // Vector to store the frequency of each character (assuming lowercase English alphabets)
    vector<int> freq(26, 0);

    // If the lengths of the strings are different, they cannot be anagrams
    if (s1.length() != s2.length()) {
        return false;
    }

    // Count the frequency of characters in the first string
    for (int i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
    }

    // Decrement the frequency of characters in the second string
    for (int i = 0; i < s2.length(); i++) {
        freq[s2[i] - 'a']--;
    }

    // Check if all character frequencies are zero, indicating the strings are anagrams
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    string s1, s2;

    // Input two strings
    cout << "Enter the first string: ";
    cin >> s1;

    cout << "Enter the second string: ";
    cin >> s2;

    // Check if the strings are anagrams and print the result
    if (anagram(s1, s2)) {
        cout << "Strings are anagrams" << endl;
    } else {
        cout << "Strings are not anagrams" << endl;
    }

    return 0;
}
