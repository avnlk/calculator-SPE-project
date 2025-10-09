#include "gtest/gtest.h"
#include "power_func.h"

TEST(PowerFunction, SimpleCases) {
    EXPECT_DOUBLE_EQ(power(2,3), 8);
    EXPECT_NEAR(power(9,0.5), 3, 1e-9);
}

