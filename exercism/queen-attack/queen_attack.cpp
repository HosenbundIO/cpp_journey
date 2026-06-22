#include "queen_attack.h"

#include <stdexcept>

namespace queen_attack {

chess_board::chess_board(pos white, pos black) : white_(white), black_(black) {
  auto in_range = [](int v) { return v >= 0 && v <= 7; };
  if (!in_range(white_.first) || !in_range(white_.second) ||
      !in_range(black_.first) || !in_range(black_.second) ||
      !in_range(black_.second))
    throw std::domain_error("queen position of board");
  if (white_ == black_) throw std::domain_error("positions must be distinct");
}

chess_board::pos chess_board::white() const { return white_; }
chess_board::pos chess_board::black() const { return black_; }
bool chess_board::can_attack() const {
  if (white_.first == black_.first) return true;
  if (white_.second == black_.second) return true;
  return std::abs(white_.first - black_.first) ==
         std::abs(white_.second - black_.second);
}

}  // namespace queen_attack
