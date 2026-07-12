#include "gtest/gtest.h"
#include "o-lukas/LibraryPlayground/StringUtil.hpp"

TEST(StringUtilTest, ToUpper) {
  const std::string input = "Hello, World!";
  const std::string output =
      o_lukas::LibraryPlayground::StringUtil::toUpper(input);
  EXPECT_EQ(output, "HELLO, WORLD!");
}

TEST(StringUtilTest, ToLower) {
  const std::string input = "Hello, World!";
  const std::string output =
      o_lukas::LibraryPlayground::StringUtil::toLower(input);
  EXPECT_EQ(output, "hello, world!");
}
