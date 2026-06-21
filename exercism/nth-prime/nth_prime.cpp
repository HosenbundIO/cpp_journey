#include "nth_prime.h"

#include <cmath>
#include <stdexcept>

namespace nth_prime {

bool is_prime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  int limit = static_cast<int>(std::sqrt(n));
  for (int i{3}; i <= limit; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}
int nth(int n) {
  if (n <= 0) {
    throw std::domain_error("Input must be a positive integer");
  }
  if (n == 1) return 2;

  int count = 1;
  int candidate = 1;

  while (count < n) {
    candidate += 2;
    if (is_prime(candidate)) {
      count++;
    }
  }
  return candidate;
}

}  // namespace nth_prime
