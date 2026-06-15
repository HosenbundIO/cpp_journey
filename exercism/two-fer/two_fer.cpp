#include "two_fer.h"

namespace two_fer {
std::string two_fer() { return "One for you, one for me."; }

std::string two_fer(std::string_view name) {
  return "One for " + std::string(name) + ", one for me.";
}
}  // namespace two_fer
