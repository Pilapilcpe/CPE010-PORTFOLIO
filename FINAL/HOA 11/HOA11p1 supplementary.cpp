//
// Created by royga on 10/6/2026.
//
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

// PROBLEM 1: Uniqueness Algorithm
bool Unique(const std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) {
                return false; // Duplicate found, not unique
            }
        }
    }
    return true; // All elements are unique
}


// PROBLEM 2: Recursive Power Functions
// Standard Linear Recursive Power: O(n)
long long rpower(long long x, int n) {
    if (n == 0) {
        return 1;
    } else {
        return x * rpower(x, n - 1);
    }
}
long long brpower(long long x, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 != 0) { // If n is odd
        long long y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else { // If n is even
        long long y = brpower(x, n / 2);
        return y * y;
    }
}




int main() {
    //Problem 1: Unique
    std::cout << "PROBLEM 1: UNIQUE ALGORITHM" << std::endl;
    std::vector<int> test_array = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    auto start1 = std::chrono::steady_clock::now();
    bool is_unique = Unique(test_array);
    auto end1 = std::chrono::steady_clock::now();

    std::cout << "Array is unique? " << (is_unique ? "True" : "False") << std::endl;
    std::cout << "Time taken for Unique: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count()
              << " microseconds\n" << std::endl;

    
    //Testing Problem 2: rpower vs brpower
    std::cout << "PROBLEM 2: POWER FUNCTIONS" << std::endl;
    long long base = 2;
    int exponent = 20; // Using a safe exponent to prevent overflow for linear rpower

    // Test standard rpower
    auto start_r = std::chrono::steady_clock::now();
    long long result_r = rpower(base, exponent);
    auto end_r = std::chrono::steady_clock::now();

    std::cout << "rpower(" << base << ", " << exponent << ") = " << result_r << std::endl;
    std::cout << "Time taken by rpower: "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end_r - start_r).count()
              << " nanoseconds" << std::endl;

    // Test optimized brpower
    auto start_br = std::chrono::steady_clock::now();
    long long result_br = brpower(base, exponent);
    auto end_br = std::chrono::steady_clock::now();

    std::cout << "brpower(" << base << ", " << exponent << ") = " << result_br << std::endl;
    std::cout << "Time taken by brpower: "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end_br - start_br).count()
              << " nanoseconds" << std::endl;

    return 0;
}