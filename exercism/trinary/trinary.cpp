#include "trinary.h"
#include <cmath>
#include <string>

namespace trinary {

// TODO: add your solution here
int to_decimal(std::string trinary_num) {
  int sum = 0;
  for (size_t i = 0; i < trinary_num.size(); i++) {

    if (trinary_num[i] < '0' || trinary_num[i] > '2') {
      return 0;
    }

    int n = trinary_num[i] - '0';
    sum += n * std::pow(3, (trinary_num.size() - i - 1));
  }
  return sum;
}
} // namespace trinary
