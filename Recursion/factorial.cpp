#include <iostream>

// Recursive function to calculate factorial
int factorial(int n) {
    // Base case: factorial of 0 is 1
    if (n == 0 || n == 1) {
        return 1;
    } else {
        // Recursive case: n! = n * (n-1)!
        return n * factorial(n - 1);
    }
}

int main() {
    // Example: Calculate factorial of 5
    int result = factorial(5);

    // Output the result
    std::cout << "Factorial of 5 is: " << result << std::endl;

    return 0;
}
