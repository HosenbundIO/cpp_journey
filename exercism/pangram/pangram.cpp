#include "pangram.h"

#include <cstdint>
namespace pangram {

bool is_pangram(const std::string& text) {
  uint32_t seen = 0;

  for (char c : text) {
    if (std::isalpha(c)) {
      int index = std::tolower(c) - 'a';

      seen |= (1 << index);

      if (seen == 0x3FFFFFF) return seen;
    }
  }

  return seen == 0x3FFFFFF;
}
}  // namespace pangram
