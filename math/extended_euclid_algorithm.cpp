/**
 * @file
 * @brief GCD using extended Euclid's algorithm
 * (https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm)
 *
 * Finding coefficients x and y for Bézout's identity:
 * \f[
 * \gcd(a, b) = a \times x + b \times y
 * \f]
 *
 * This algorithm is also used to compute the Modular Multiplicative Inverse
 * (MMI). If (A × B) % M == 1, then B is MMI(A, M), and
 * extended_euclid_recursive(A, M) provides B.
 */

#include <iostream>
using namespace std;

/**
 * @brief Recursive Extended Euclid Algorithm
 *
 * This method recursively applies the idea that:
 * \f[
 * \gcd(a, b) = \gcd(b,\, a \bmod b)
 * \f]
 *
 * Each recursive step reduces the problem size by replacing (a, b)
 * with (b, a % b). Once b becomes 0, the algorithm has reached the base
 * case, where gcd = a and the Bézout coefficients (x, y) are known.
 *
 * On returning from recursion, the coefficients are updated in reverse
 * order using:
 * \f[
 * x = y_1,\qquad
 * y = x_1 - \left\lfloor \frac{a}{b} \right\rfloor \cdot y_1
 * \f]
 *
 * This back-substitution step reconstructs the Bézout identity
 * for the original pair (a, b).
 *
 * @param[in] a first number
 * @param[in] b second number
 * @param[out] gcd greatest common divisor
 * @param[out] x coefficient of a
 * @param[out] y coefficient of b
 */
void extended_euclid_recursive(long long a, long long b, long long& gcd,
                               long long& x, long long& y) {
    if (b == 0) {
        gcd = a;
        x = 1;
        y = 0;
        return;
    }

    long long x1, y1;
    extended_euclid_recursive(b, a % b, gcd, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;
}

/**
 * @brief Iterative Extended Euclid Algorithm
 *
 * This version performs the same transformations as the recursive method
 * but unfolds the process into a loop. It repeatedly updates (a, b)
 * using the identity:
 * \f[
 * (a, b) \rightarrow (b,\; a - \lfloor a/b \rfloor \cdot b)
 * \f]
 *
 * Alongside (a, b), it maintains two pairs of coefficients (x0, y0) and
 * (x1, y1) which evolve according to the same quotient used during each
 * division step. Once b becomes zero, the surviving values (x0, y0)
 * form the Bézout coefficients:
 * \f[
 * a \times x_0 + b_{\text{original}} \times y_0 = \gcd(a, b)
 * \f]
 *
 * This approach avoids recursion and makes the sequence of updates
 * easier to trace step-by-step.
 *
 * @param[in] a first number
 * @param[in] b second number
 * @param[out] gcd greatest common divisor
 * @param[out] x coefficient of a
 * @param[out] y coefficient of b
 */
void extended_euclid_iterative(long long a, long long b, long long& gcd,
                               long long& x, long long& y) {
    long long x0 = 1, y0 = 0, x1 = 0, y1 = 1;

    while (b != 0) {
        long long q = a / b, temp = b;
        b = a - q * b;
        a = temp;

        temp = x1;
        x1 = x0 - q * x1;
        x0 = temp;

        temp = y1;
        y1 = y0 - q * y1;
        y0 = temp;
    }

    gcd = a;
    x = x0;
    y = y0;
}

/**
 * @brief Self-test examples in your preferred style
 */
void test() {
    // Test 0
    long long gcd0, x0, y0;
    cout << "Test 0" << endl;
    cout << "Input: a = 30 and b = 20" << endl;

    extended_euclid_recursive(30, 20, gcd0, x0, y0);
    cout << "Recursive => gcd: " << gcd0 << "  x: " << x0 << "  y: " << y0
         << endl;

    extended_euclid_iterative(30, 20, gcd0, x0, y0);
    cout << "Iterative => gcd: " << gcd0 << "  x: " << x0 << "  y: " << y0
         << endl;

    // Test 1
    long long gcd1, x1, y1;
    cout << "Test 1" << endl;
    cout << "Input: a = 101 and b = 23" << endl;

    extended_euclid_recursive(101, 23, gcd1, x1, y1);
    cout << "Recursive => gcd: " << gcd1 << "  x: " << x1 << "  y: " << y1
         << endl;

    extended_euclid_iterative(101, 23, gcd1, x1, y1);
    cout << "Iterative => gcd: " << gcd1 << "  x: " << x1 << "  y: " << y1
         << endl;

    // Test 2
    long long gcd2, x2, y2;
    cout << "Test 2" << endl;
    cout << "Input: a = 55 and b = 34" << endl;

    extended_euclid_recursive(55, 34, gcd2, x2, y2);
    cout << "Recursive => gcd: " << gcd2 << "  x: " << x2 << "  y: " << y2
         << endl;

    extended_euclid_iterative(55, 34, gcd2, x2, y2);
    cout << "Iterative => gcd: " << gcd2 << "  x: " << x2 << "  y: " << y2
         << endl;
}

/// Main function
int main() {
    test();  // run self-test examples
    return 0;
}