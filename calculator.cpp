#include "calculator.h"
#include <stdexcept>

double calculate_square_root(double n) {
    if (n < 0) {
        throw std::invalid_argument("Square root of negative number is not real.");
    }
    return sqrt(n);
}

unsigned long long calculate_factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Factorial of negative number is not defined.");
    }
    if (n > 20) {
        throw std::overflow_error("Factorial of number greater than 20 is too large to fit in unsigned long long.");
    }
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    return factorial;
}

double calculate_natural_log(double n) {
    if (n <= 0) {
        throw std::invalid_argument("Natural logarithm of non-positive number is not defined.");
    }
    return log(n);
}

double calculate_power(double base, double exponent) {
    return pow(base, exponent);
}