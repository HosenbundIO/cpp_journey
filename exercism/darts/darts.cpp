#include "darts.h"
#include "cmath"

namespace darts {

// TODO: add your solution here
int score(float x, float y) {
    float r = std::hypot(x, y);
    if (r <= 1.0f) return 10;
    else if (r <= 5.0f) return 5;
    else if (r <= 10.0f) return 1;
    else return 0;
}
}  // namespace darts
