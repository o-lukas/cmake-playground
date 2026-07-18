#include "o-lukas/StringUtils/StringUtil.hpp"

#include <cctype>

namespace o_lukas::StringUtils {

std::string StringUtil::toUpper(const std::string& input) {
  std::string result = input;
  for (char& ch : result) {
    ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
  }
  return result;
}

std::string StringUtil::toLower(const std::string& input) {
  std::string result = input;
  for (char& ch : result) {
    ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
  }
  return result;
}

}  // namespace o_lukas::StringUtils
