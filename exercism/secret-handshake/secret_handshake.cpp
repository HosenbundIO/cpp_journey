#include "secret_handshake.h"

namespace secret_handshake {

std::vector<std::string> commands(const int& a) {
  std::vector<std::string> actions;

  if (a & 0b00001) actions.push_back("wink");
  if (a & 0b00010) actions.push_back("double blink");
  if (a & 0b00100) actions.push_back("close your eyes");
  if (a & 0b01000) actions.push_back("jump");

  if (a & 0b10000) {
    std::reverse(actions.begin(), actions.end());
  }
  return actions;
}

}  // namespace secret_handshake
