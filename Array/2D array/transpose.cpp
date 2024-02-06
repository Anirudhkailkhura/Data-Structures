// transpose of matrix

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // Corrected input operator from >

    int A[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { // Corrected loop variable from i to j
            cin >> A[i][j]; // Corrected array access from A[i][j]
        }
    }

    int transpose[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) { // Corrected loop variable from i to j
            transpose[i][j] = A[j][i]; // Corrected array access and assignment
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) { // Corrected loop variable from i to j
            cout << transpose[i][j] << " "; // Corrected array access from transpose[m][n]
        }
        cout << endl;
    }

    return 0;
}
