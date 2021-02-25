#pragma once

#include <string>
#include <string_view>
#include <tuple>

namespace cryptopals
{

int score_english_character_freq(std::string_view text);

struct FrequencyAnalysisResult
{
    int score;
    char key;
    std::string plain_text;
};

bool operator<(const FrequencyAnalysisResult &lhs,
               const FrequencyAnalysisResult &rhs);

FrequencyAnalysisResult best_score_with_single_char_xor(std::string_view text);

} // namespace cryptopals
