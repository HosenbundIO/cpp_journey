#pragma once

#include <string>

namespace rna_transcription {
char to_rna(const char dna_s);
std::string to_rna(std::string_view dna_s);
}  // namespace rna_transcription
