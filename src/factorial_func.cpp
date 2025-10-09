#include <stdexcept>
#include "factorial_func.h"

unsigned long long factorial(int n) {
    if (n < 0)
        throw std::invalid_argument("Factorial of negative number not defined");

    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i)
        result *= i;
    return result;
}

