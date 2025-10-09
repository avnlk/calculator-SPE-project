#include <cmath>
#include <stdexcept>
#include "sqrt_func.h"

double squareRoot(double x) {
    if (x < 0)
        throw std::invalid_argument("Square root of negative number not allowed");
    return std::sqrt(x);
}

