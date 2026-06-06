#pragma once
#include <string>
#include <vector>

namespace lasagna_master {

struct amount {
  int noodles;
  double sauce;
};

int preparationTime(const std::vector<std::string>& layers,
                    const int avg_time_per_layer = 2);

amount quantities(const std::vector<std::string>& layers);

void addSecretIngredient(std::vector<std::string>& own_ingredients,
                         const std::vector<std::string>& friends_ingredients);

void addSecretIngredient(std::vector<std::string>& own_ingredients,
                         const std::string& secret_ingredient);

std::vector<double> scaleRecipe(
    const std::vector<double>& amount_needed_for_2_portions,
    const int number_of_portions);
}  // namespace lasagna_master
