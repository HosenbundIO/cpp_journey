#pragma once

#include <memory>
#include <string>

namespace troy {

struct artifact {
  // constructors needed (until C++20)
  artifact(std::string name) : name(name) {}
  std::string name;
};

struct power {
  // constructors needed (until C++20)
  power(std::string effect) : effect(effect) {}
  std::string effect;
};

class human {
 public:
  human() = default;
  std::unique_ptr<artifact> possession;
  std::shared_ptr<power> own_power;
  std::shared_ptr<power> influenced_by;
};

void give_new_artifact(human& h, const std::string& new_artifact);
void exchange_artifacts(std::unique_ptr<artifact>& a,
                        std::unique_ptr<artifact>& b);
void manifest_power(human& h, std::string new_power);
void use_power(human& h1, human& h2);
int power_intensity(const human& h);
}  // namespace troy
