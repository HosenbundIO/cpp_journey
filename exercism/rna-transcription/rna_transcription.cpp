#include "rna_transcription.h"

namespace rna_transcription {
char to_rna(const char dna_s) {
  switch (dna_s) {
    case 'G':
      return 'C';
    case 'C':
      return 'G';
    case 'T':
      return 'A';
    case 'A':
      return 'U';
    default:
      return ' ';
  }
}

std::string to_rna(const std::string_view dna_s) {
  std::string rna;
  rna.reserve(dna_s.size());
  for (char s : dna_s) {
    rna += to_rna(s);
  }
  return rna;
}
}  // namespace rna_transcription
