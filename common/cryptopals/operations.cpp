#include <algorithm>
#include <cassert>
#include <functional>
#include <numeric>

#include "cryptopals/conversions.h"
#include "cryptopals/operations.h"

namespace cryptopals
{

std::string hex_xor(const std::string &hex_string_1,
                    const std::string &hex_string_2)
{
    assert(hex_string_1.size() == hex_string_2.size());
    auto result =
        bit_xor(hex_to_bytes(hex_string_1), hex_to_bytes(hex_string_2));
    return bytes_to_hex(result);
}

std::string bit_xor(const std::string &bytes_1, const std::string &bytes_2)
{
    assert(bytes_1.size() == bytes_2.size());
    std::string result(bytes_1.size(), 0);
    std::transform(begin(bytes_1), end(bytes_1), begin(bytes_2), begin(result),
                   std::bit_xor<char>{});
    return result;
}

std::string bit_xor(const std::string &bytes, const char c)
{
    std::string result(bytes.size(), 0);
    std::transform(begin(bytes), end(bytes), begin(result),
                   [&](char b) { return c ^ b; });
    return result;
}

static const std::string letter_by_frequency = "etaoinshrdlcumwfgypbvkjxqz";

static int character_frequency_score(char c)
{
    auto pos = letter_by_frequency.find(c);
    if (pos == std::string::npos)
        pos = letter_by_frequency.size();
    return letter_by_frequency.size() - pos;
}

int score_english_character_freq(const std::string &text)
{
    return std::accumulate(begin(text), end(text), 0,
                           [](int score, char c)
                           { return score + character_frequency_score(c); });
}

} // namespace cryptopals
