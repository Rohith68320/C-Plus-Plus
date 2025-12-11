/**
 * @file
 * @brief C++ Program to find Binary Exponent Iteratively and Recursively.
 *
 * Calculate a^b in O(log(b)) by converting b to a
 * binary number. Binary exponentiation is also known as exponentiation by
 * squaring.
 * @note This is a far better approach compared to naive method which
 * provide O(b) operations.
 *
 * Example:
 * 10 in base 2 is 1010.
 * {eqnarray*}{
 * 2^{10_d} = 2^{1010_b} = 2^8 * 2^2\\
 * 2^1 = 2\\
 * 2^2 = (2^1)^2 = 2^2 = 4\\ṇ
 * 2^4 = (2^2)^2 = 4^2 = 16\\
 * 2^8 = (2^4)^2 = 16^2 = 256\\
 * \f}
 * Hence to calculate 2^10 we only need to multiply 2^8 and 2^2
 * skipping 2^1 and 2^4.
 */

#include <iostream>
using namespace std;

/// Recursive function to calculate exponent in O(log(n)) using binary
/// exponent.
// Use long long for avoiding overflow.
long long binary_exponent_recursive(long long base, long long exponent) {
    if (exponent == 0) {
        return 1;
    }
    long long half = binary_exponent_recursive(base, exponent / 2);
    if (exponent % 2) {
        return half * half * base;
    } else {
        return half * half;
    }
}

/// Iterative function to calculate exponent in \f$O(\log(n))\f$ using binary
/// exponent.
/// Use long long for avoiding Overflow
long long binary_exponent_iterative(long long base, long long exponent) {
    long long res = 1;
    while (exponent > 0) {
        if (exponent % 2) {
            res *= base;
        }
        base = base * base;
        exponent >>= 1;
    }
    return res;
}

//@brief Self-test examples for verifying
void test() {
    // Test 0
    long long expected0 = 1024;
    cout << "Test 0" << endl;
    cout << "Input: base = 2 and exponent = 10" << endl;
    cout << "Expected: " << expected0 << endl;
    cout << "Recursive: " << binary_exponent_recursive(2, 10) << endl;
    cout << "Iterative: " << binary_exponent_iterative(2, 10) << endl;
    cout << endl;

    // Test 1
    long long expected1 = 2187;
    cout << "Test 1" << endl;
    cout << "Input: base = 3 and exponent = 7" << endl;
    cout << "Expected: " << expected1 << endl;
    cout << "Recursive: " << binary_exponent_recursive(3, 7) << endl;
    cout << "Iterative: " << binary_exponent_iterative(3, 7) << endl;
    cout << endl;

    // Test 2
    long long expected2 = 16777216;
    cout << "Test 2" << endl;
    cout << "Input: base = 4 and exponent = 12" << endl;
    cout << "Expected: " << expected2 << endl;
    cout << "Recursive: " << binary_exponent_recursive(4, 12) << endl;
    cout << "Iterative: " << binary_exponent_iterative(4, 12) << endl;
    cout << endl;

    // Test 3
    long long expected3 = 30517578125;
    cout << "Test 3" << endl;
    cout << "Input: base = 5 and exponent = 15" << endl;
    cout << "Expected: " << expected3 << endl;
    cout << "Recursive: " << binary_exponent_recursive(5, 15) << endl;
    cout << "Iterative: " << binary_exponent_iterative(5, 15) << endl;
    cout << endl;

    // Test 4
    long long expected4 = 3656158440062976;
    cout << "Test 4" << endl;
    cout << "Input: base = 6 and exponent = 20" << endl;
    cout << "Expected: " << expected4 << endl;
    cout << "Recursive: " << binary_exponent_recursive(6, 20) << endl;
    cout << "Iterative: " << binary_exponent_iterative(6, 20) << endl;
    cout << endl;
}

/// Main function
int main() {
    test();  // run self-test examples
    return 0;
}