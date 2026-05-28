#include "raindrops.h"
#include <string>

namespace raindrops {

// TODO: add your solution here
std::string convert(int num) {
  std::string result = "";

  if (num % 3 == 0)
    result += "Pling";
  if (num % 5 == 0)
    result += "Plang";
  if (num % 7 == 0)
    result += "Plong";

  if (result == "")
    return std::to_string(num);
  return result;
};
} // namespace raindrops
