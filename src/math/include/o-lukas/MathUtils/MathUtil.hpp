#pragma once

namespace o_lukas::MathUtils {
class MathUtil {
 public:
  static int add(int a, int b);
  static int multiply(int a, int b);
  static double clamp(double value, double min, double max);
};
}  // namespace o_lukas::MathUtils
