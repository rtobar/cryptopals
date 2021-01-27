#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>

#include "cryptopals/conversions.h"
#include "cryptopals/operations.h"

namespace cryptopals
{

std::tuple<char, std::string>
best_score_with_single_char_xor(const std::string &hex)
{
    auto text = hex_to_bytes(hex);
    std::vector<int> scores;
    for (int c = 0; c < 255; c++)
    {
        auto score = score_english_character_freq(bit_xor(text, char(c)));
        scores.push_back(score);
    }
    auto key = std::distance(begin(scores),
                             std::max_element(begin(scores), end(scores)));
    return {key, bit_xor(text, key)};
}

} // namespace cryptopals

int main(int argc, char *argv[])
{
    assert(argc > 1);
    auto [key, plain_text] =
        cryptopals::best_score_with_single_char_xor(argv[1]);
    std::cout << "key: " << key << ", plain text: " << plain_text << '\n';
}
