#pragma once

#include <string>

#include "o-lukas/StringUtils/Export.hpp"

namespace o_lukas::StringUtils {
/**
 * @brief Utility functions for string transformations.
 */
class STRING_UTILS_EXPORT StringUtil {
 public:
  /**
   * @brief Convert a string to uppercase.
   *
   * @param input The input string.
   * @return A new string with all characters converted to upper case.
   */
  static std::string toUpper(const std::string& input);

  /**
   * @brief Convert a string to lowercase.
   *
   * @param input The input string.
   * @return A new string with all characters converted to lower case.
   */
  static std::string toLower(const std::string& input);
};
}  // namespace o_lukas::StringUtils
