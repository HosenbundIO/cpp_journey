#include "say.h"

#include <stdexcept>
#include <vector>

namespace say {

std::string in_english(long long n) {
  if (n < 0 || n > 999999999999LL) {
    throw std::domain_error("Number out of range");
  }
  if (n == 0) return "zero";

  static const std::vector<std::string> ones = {
      "",        "one",     "two",       "three",    "four",
      "five",    "six",     "seven",     "eight",    "nine",
      "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
      "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

  static const std::vector<std::string> tens = {
      "",      "",      "twenty",  "thirty", "forty",
      "fifty", "sixty", "seventy", "eighty", "ninety"};

  auto convert_chunk = [&](int n) -> std::string {
    std::string s;
    if (n >= 100) {
      s += ones[n / 100] + " hundred ";
      n %= 100;
    }
    if (n >= 20) {
      s += tens[n / 10] + (n % 10 != 0 ? "-" + ones[n % 10] : "");

    } else if (n > 0) {
      s += ones[n];
    }
    return s;
  };

  std::string result;
  std::vector<std::string> scales = {"", "thousand", "million", "billion"};

  int scale_idx = 0;
  while (n > 0) {
    if (n % 1000 != 0) {
      std::string chunk = convert_chunk(n % 1000);

      std::string segment = chunk;
      if (!scales[scale_idx].empty()) {
        segment += " " + scales[scale_idx];
      }

      if (result.empty()) {
        result = segment;
      } else {
        result = segment + " " + result;
      }
    }
    n /= 1000;
    scale_idx++;
  }
  if (!result.empty() && result.back() == ' ') result.pop_back();

  return result;
}

}  // namespace say
