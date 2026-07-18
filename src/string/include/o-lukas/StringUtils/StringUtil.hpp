#pragma once

#include <string>

namespace o_lukas::StringUtils {
class StringUtil {
 public:
  static std::string toUpper(const std::string& input);
  static std::string toLower(const std::string& input);
};
}  // namespace o_lukas::StringUtils
