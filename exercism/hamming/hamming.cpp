#include "hamming.h"

#include <stdexcept>

namespace hamming {
int compute(const std::string_view a, const std::string_view b) {
  if (a.size() != b.size()) {
    throw std::domain_error("Strands must be of equal length.");
  }

  int count{0};
  for (size_t i{0}; i < a.size(); ++i) {
    if (a[i] != b[i]) ++count;
  }
  return count;
}
}  // namespace hamming
