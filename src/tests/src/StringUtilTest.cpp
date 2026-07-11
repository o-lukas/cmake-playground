#include <iostream>
#include <string>

#include "o-lukas/LibraryPlayground/StringUtil.hpp"

int main() {
  const std::string input = "Hello, World!";

  const std::string upper =
      o_lukas::LibraryPlayground::StringUtil::toUpper(input);
  const std::string lower =
      o_lukas::LibraryPlayground::StringUtil::toLower(input);

  std::cout << "Upper: " << upper << '\n';
  std::cout << "Lower: " << lower << '\n';

  return (upper == "HELLO, WORLD!") && (lower == "hello, world!") ? 0 : 1;
}
