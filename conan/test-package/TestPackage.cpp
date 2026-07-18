#include <iostream>
#include <o-lukas/MathUtils/MathUtil.hpp>
#include <o-lukas/StringUtils/StringUtil.hpp>
#include <string>

int main() {
  {
    const auto input = "Hello, World!";
    const auto output = o_lukas::StringUtils::StringUtil::toUpper(input);

    std::cout << "o_lukas::StringUtils::StringUtil::toUpper" << std::endl;
    std::cout << "Input: " << input << std::endl;
    std::cout << "Output: " << output << std::endl;
  }

  {
    const auto input1 = 5;
    const auto input2 = 3;
    const auto output = o_lukas::MathUtils::MathUtil::add(input1, input2);

    std::cout << "o_lukas::MathUtils::MathUtil::add" << std::endl;
    std::cout << "Input: " << input1 << ", " << input2 << std::endl;
    std::cout << "Output: " << output << std::endl;
  }

  return 0;
}
