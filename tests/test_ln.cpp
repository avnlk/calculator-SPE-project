#include "gtest/gtest.h"
#include "ln_func.h"
#include <cmath>

TEST(LnFunction, PositiveNumbers) {
    EXPECT_NEAR(naturalLog(std::exp(1.0)), 1.0, 1e-9);
}

TEST(LnFunction, NonPositive) {
    EXPECT_THROW(naturalLog(0), std::invalid_argument);
}

