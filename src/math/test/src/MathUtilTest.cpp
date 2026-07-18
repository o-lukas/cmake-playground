#include "gtest/gtest.h"
#include "o-lukas/MathUtils/MathUtil.hpp"

TEST(MathTest, Add) {
  EXPECT_EQ(o_lukas::MathUtils::MathUtil::add(2, 3), 5);
  EXPECT_EQ(o_lukas::MathUtils::MathUtil::add(-1, 1), 0);
}

TEST(MathTest, Multiply) {
  EXPECT_EQ(o_lukas::MathUtils::MathUtil::multiply(4, 5), 20);
  EXPECT_EQ(o_lukas::MathUtils::MathUtil::multiply(-2, 3), -6);
}

TEST(MathTest, Clamp) {
  EXPECT_DOUBLE_EQ(o_lukas::MathUtils::MathUtil::clamp(5.0, 0.0, 10.0), 5.0);
  EXPECT_DOUBLE_EQ(o_lukas::MathUtils::MathUtil::clamp(-1.0, 0.0, 10.0), 0.0);
  EXPECT_DOUBLE_EQ(o_lukas::MathUtils::MathUtil::clamp(11.0, 0.0, 10.0), 10.0);
}
