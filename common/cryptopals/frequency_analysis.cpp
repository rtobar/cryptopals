#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

#include "cryptopals/frequency_analysis.h"
#include "cryptopals/xor.h"

namespace cryptopals
{

static const std::string letter_by_frequency = "etaoinshrdlcumwfgypbvkjxqz";

static int character_frequency_score(char c)
{
    auto pos = letter_by_frequency.find(c);
    if (pos == std::string::npos)
        pos = letter_by_frequency.size();
    return letter_by_frequency.size() - pos;
}

int score_english_character_freq(std::string_view text)
{
    return std::accumulate(begin(text), end(text), 0,
                           [](int score, char c)
                           { return score + character_frequency_score(c); });
}

bool operator<(const FrequencyAnalysisResult &lhs,
               const FrequencyAnalysisResult &rhs)
{
    return lhs.score < rhs.score;
}

FrequencyAnalysisResult best_score_with_single_char_xor(std::string_view text)
{
    std::vector<int> scores;
    for (int c = 0; c < 255; c++)
    {
        auto score = score_english_character_freq(bit_xor(text, char(c)));
        scores.push_back(score);
    }
    auto best_score = std::max_element(begin(scores), end(scores));
    auto key = std::distance(begin(scores), best_score);
    assert(key < 256);
    return {*best_score, static_cast<char>(key), bit_xor(text, key)};
}

} // namespace cryptopals
