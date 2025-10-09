#include "gtest/gtest.h"
#include "sqrt_func.h"

TEST(SqrtFunction, PositiveNumbers) {
    EXPECT_DOUBLE_EQ(squareRoot(9.0), 3.0);
    EXPECT_DOUBLE_EQ(squareRoot(0.0), 0.0);
}

TEST(SqrtFunction, NegativeNumbers) {
    EXPECT_THROW(squareRoot(-4.0), std::invalid_argument);
}

