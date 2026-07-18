#include "o-lukas/MathUtils/MathUtil.hpp"

namespace o_lukas::MathUtils {

int MathUtil::add(int a, int b) { return a + b; }

int MathUtil::multiply(int a, int b) { return a * b; }

double MathUtil::clamp(double value, double min, double max) {
  if (value < min) return min;
  if (value > max) return max;
  return value;
}

}  // namespace o_lukas::MathUtils
