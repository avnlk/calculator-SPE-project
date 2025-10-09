#include "gtest/gtest.h"
#include "factorial_func.h"

TEST(FactorialFunction, PositiveNumbers) {
    EXPECT_EQ(factorial(5), 120);
    EXPECT_EQ(factorial(0), 1);
}

TEST(FactorialFunction, NegativeNumbers) {
    EXPECT_THROW(factorial(-3), std::invalid_argument);
}

