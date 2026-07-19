#pragma once

namespace o_lukas::MathUtils {
/**
 * @brief Basic math utility functions.
 */
class MathUtil {
 public:
  /**
   * @brief Add two integers.
   *
   * @param a The first addend.
   * @param b The second addend.
   * @return The sum of a and b.
   */
  static int add(int a, int b);

  /**
   * @brief Multiply two integers.
   *
   * @param a The first factor.
   * @param b The second factor.
   * @return The product of a and b.
   */
  static int multiply(int a, int b);

  /**
   * @brief Clamp a value between a minimum and maximum.
   *
   * @param value The value to clamp.
   * @param min The lower bound.
   * @param max The upper bound.
   * @return The clamped value.
   */
  static double clamp(double value, double min, double max);
};
}  // namespace o_lukas::MathUtils
