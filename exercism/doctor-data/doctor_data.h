#pragma once
#include <string>

namespace star_map {
enum class System {
  BetaHydri,
  Sol,
  EpsilonEridani,
  AlphaCentauri,
  DeltaEridani,
  Omicron2Eridani
};
}

namespace heaven {
class Vessel {
 private:
 public:
  std::string name;
  int generation;
  star_map::System current_system;
  int busters{0};

  Vessel(std::string name, int generation,
         star_map::System current_system = star_map::System::Sol)
      : name(name), generation(generation), current_system(current_system) {};

  Vessel replicate(std::string name) {
    return Vessel(name, this->generation + 1, this->current_system);
  }

  void make_buster() { this->busters += 1; }
  bool shoot_buster() {
    if (this->busters > 0) {
      this->busters -= 1;
      return true;
    } else {
      return false;
    }
  }
};
std::string_view get_older_bob(const Vessel& v1, const Vessel& v2);
bool in_the_same_system(const Vessel& v1, const Vessel& v2);

}  // namespace heaven
