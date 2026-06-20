#include "collatz_conjecture.h"

#include <stdexcept>

namespace collatz_conjecture {

int steps(int a) {
    if (a <= 0) throw std::domain_error("Only positive integers are allowed");
    if (a == 1) return 0;
    if (a % 2 == 0) return 1 + steps(a / 2);
    return 1 + steps(a * 3 + 1);
}

}  // namespace collatz_conjecture
