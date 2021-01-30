#pragma once

#include <string>
#include <tuple>

namespace cryptopals
{

int score_english_character_freq(const std::string &text);

struct FrequencyAnalysisResult
{
    int score;
    char key;
    std::string plain_text;
};

bool operator<(const FrequencyAnalysisResult &lhs,
               const FrequencyAnalysisResult &rhs);

FrequencyAnalysisResult best_score_with_single_char_xor(const std::string &text);

} // namespace cryptopals
