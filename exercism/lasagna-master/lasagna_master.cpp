#include "lasagna_master.h"

namespace lasagna_master {

// TODO: add your solution here
int preparationTime(const std::vector<std::string>& layers,
                    const int avg_time_per_layer) {
  return layers.size() * avg_time_per_layer;
}

amount quantities(const std::vector<std::string>& layers) {
  amount result{};

  for (const auto& layer : layers) {
    if (layer == "noodles") {
      result.noodles += 50;
    } else if (layer == "sauce") {
      result.sauce += 0.2;
    }
  }

  return result;
}

void addSecretIngredient(std::vector<std::string>& own_ingredients,
                         const std::vector<std::string>& friends_ingredients) {
  if (!own_ingredients.empty() && !friends_ingredients.empty()) {
    own_ingredients.back() = friends_ingredients.back();
  }
}

void addSecretIngredient(std::vector<std::string>& own_ingredients,
                         const std::string& secret_ingredient) {
  if (!own_ingredients.empty()) {
    own_ingredients.back() = secret_ingredient;
  }
}

std::vector<double> scaleRecipe(const std::vector<double>& amounts,
                                const int portions) {
  const double factor = static_cast<double>(portions) / 2.0;
  std::vector<double> scaled_amounts = amounts;

  for (auto& amount : scaled_amounts) {
    amount *= factor;
  }
  return scaled_amounts;
}
}  // namespace lasagna_master
