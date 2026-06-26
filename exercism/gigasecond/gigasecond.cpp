#include "gigasecond.h"

namespace gigasecond {

static constexpr long GIGASECOND_SECONDS = 1'000'000'000;

ptime advance(const ptime& start_time) {
  return start_time + seconds(GIGASECOND_SECONDS);
}

}  // namespace gigasecond
