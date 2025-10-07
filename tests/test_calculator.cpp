#include "gtest/gtest.h"
#include "../calculator.h"
#include <stdexcept>

TEST(CalculatorTest, Power) {
    EXPECT_EQ(calculate_power(2, 3), 8);
    EXPECT_EQ(calculate_power(5, 2), 25);
    EXPECT_EQ(calculate_power(10, 0), 1);
}

TEST(CalculatorTest, SquareRoot) {
    EXPECT_EQ(calculate_square_root(9), 3);
    EXPECT_EQ(calculate_square_root(16), 4);
    EXPECT_EQ(calculate_square_root(0), 0);
    EXPECT_THROW(calculate_square_root(-1), std::invalid_argument);
}

TEST(CalculatorTest, NaturalLog) {
    EXPECT_NEAR(calculate_natural_log(1), 0, 0.001);
    EXPECT_NEAR(calculate_natural_log(2.71828), 1, 0.001);
    EXPECT_THROW(calculate_natural_log(0), std::invalid_argument);
    EXPECT_THROW(calculate_natural_log(-1), std::invalid_argument);
}

TEST(CalculatorTest, Factorial) {
    EXPECT_EQ(calculate_factorial(5), 120);
    EXPECT_EQ(calculate_factorial(0), 1);
    EXPECT_EQ(calculate_factorial(1), 1);
    EXPECT_THROW(calculate_factorial(-1), std::invalid_argument);
    EXPECT_THROW(calculate_factorial(21), std::overflow_error);
}