#include <cmath>
#include <stdexcept>
#include "ln_func.h"

double naturalLog(double x) {
    if (x <= 0)
        throw std::invalid_argument("Natural log undefined for non-positive values");
    return std::log(x);
}

