#include "grains.h"

namespace grains {

unsigned long long square(const int& s) { return 1ULL << (s - 1); }
unsigned long long total() { return ~0ULL; }
}  // namespace grains
