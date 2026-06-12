#pragma once

#include <stdexcept>
namespace triangle {

enum class flavor { equilateral, isosceles, scalene };

inline flavor kind(double a, double b, double c) {
  if (a <= 0 || b <= 0 || c <= 0 || (a + b < c) || (a + c < b) || (b + c < a)) {
    throw std::domain_error("Error: Invalid triangle dimensions");
  }

  if (a == b && b == c) {
    return flavor::equilateral;
  }

  if (a == b || b == c || a == c) {
    return flavor::isosceles;
  }

  return flavor::scalene;
}
}  // namespace triangle
