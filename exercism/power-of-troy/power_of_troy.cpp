#include "power_of_troy.h"

#include <memory>

namespace troy {

void give_new_artifact(human& h, const std::string& new_artifact) {
  h.possession = std::make_unique<artifact>(new_artifact);
}

void exchange_artifacts(std::unique_ptr<artifact>& a,
                        std::unique_ptr<artifact>& b) {
  std::swap(a, b);
}

void manifest_power(human& h, std::string new_power) {
  h.own_power = std::make_shared<power>(std::move(new_power));
}

void use_power(human& h1, human& human2) {
  human2.influenced_by = h1.own_power;
}

int power_intensity(const human& h) {
  return h.own_power == nullptr ? 0 : h.own_power.use_count();
}
}  // namespace troy
