#include "protein_translation.h"

#include <unordered_map>

namespace protein_translation {

// TODO: add your solution here
std::vector<std::string> proteins(const std::string& rna_sequence) {
  static const std::unordered_map<std::string_view, std::string> codons{
      {"AUG", "Methionine"}, {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
      {"UUA", "Leucine"},    {"UUG", "Leucine"},       {"UCU", "Serine"},
      {"UCC", "Serine"},     {"UCA", "Serine"},        {"UCG", "Serine"},
      {"UAU", "Tyrosine"},   {"UAC", "Tyrosine"},      {"UGU", "Cysteine"},
      {"UGC", "Cysteine"},   {"UGG", "Tryptophan"},    {"UAA", "Stop"},
      {"UAG", "Stop"},       {"UGA", "Stop"}};

  std::vector<std::string> protein{};

  for (size_t i{0}; i + 3 <= rna_sequence.size(); i += 3) {
    std::string_view codon(rna_sequence.data() + i, 3);

    auto it = codons.find(codon);
    if (it->second == "Stop") break;

    protein.emplace_back(it->second);
  }
  return protein;
}
}  // namespace protein_translation
