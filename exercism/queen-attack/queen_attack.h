#pragma once
#include <utility>

namespace queen_attack {

class chess_board {
 public:
  using pos = std::pair<int, int>;

  chess_board(pos white, pos black);
  pos white() const;
  pos black() const;
  bool can_attack() const;

 private:
  pos white_;
  pos black_;
};

}  // namespace queen_attack
