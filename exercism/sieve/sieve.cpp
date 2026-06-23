#include "sieve.h"

#include <numeric>
#include <vector>

namespace sieve {

std::vector<int> const primes2(const int& n) {
  if (n < 2) return {};

  std::vector<int> sieve(n + 1);
  std::iota(sieve.begin(), sieve.end(), 0);

  for (int i{2}; i * i <= n; ++i) {
    if (sieve[i] > 0) {
      for (int j = i * i; j <= n; j += i) {
        sieve[j] = 0;
      }
    }
  }

  std::vector<int> result;
  for (int i{2}; i <= n; ++i) {
    if (sieve[i] != 0) result.push_back(sieve[i]);
  }
  return result;
}

std::vector<int> const primes(const int& n) {
  if (n < 2) return {};
  std::vector<int> sieve((n - 1) / 2, 1);

  for (size_t i{0}; i < sieve.size(); ++i) {
    if (!sieve[i]) continue;

    int p = 2 * i + 3;
    if ((long long)p * p > n) break;
    for (size_t j = (p * p - 3) / 2; j < sieve.size(); j += p) sieve[j] = 0;
  }
  std::vector<int> r;
  r.push_back(2);

  for (size_t i{0}; i < sieve.size(); ++i) {
    if (sieve[i]) {
      r.push_back(2 * i + 3);
    }
  }
  return r;
}
}  // namespace sieve
