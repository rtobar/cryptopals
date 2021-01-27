#pragma once

#include <string>

namespace cryptopals
{
std::string hex_xor(const std::string &hex_string_1,
                    const std::string &hex_string_2);

std::string bit_xor(const std::string &bytes_1, const std::string &bytes_2);

std::string bit_xor(const std::string &bytes, const char c);

int score_english_character_freq(const std::string &text);
}; // namespace cryptopals
