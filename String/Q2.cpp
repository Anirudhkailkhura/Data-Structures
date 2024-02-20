#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to perform count sort on the given string
string countSort(string str) {
    // Create an array to store the frequency of each character (assuming lowercase English letters)
    vector<int> freq(26, 0);

    // Count the frequency of each character in the input string
    for (int i = 0; i < str.length(); i++) {
        int index = str[i] - 'a'; // Calculate the index of the character in the frequency array
        freq[index]++;
    }

    // Reconstruct the sorted string based on the character frequencies
    int j = 0;
    for (int i = 0; i < 26; i++) {
        while (freq[i]--) {
            str[j++] = i + 'a'; // Add characters to the string in sorted order based on frequency
        }
    }

    // Return the sorted string
    return str;
}

// Main function
int main() {
    string str;

    // Input the string from the user
    cout << "Enter a string: ";
    cin >> str;

    // Perform count sort and display the result
    cout << "Sorted string: " << countSort(str) << endl;

    return 0;
}
