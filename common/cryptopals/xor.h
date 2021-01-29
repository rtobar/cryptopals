#pragma once

#include <string>

namespace cryptopals
{
std::string hex_xor(const std::string &hex_string_1,
                    const std::string &hex_string_2);

std::string bit_xor(const std::string &bytes_1, const std::string &bytes_2);

std::string bit_xor(const std::string &bytes_1, const char *key, int key_size);

std::string bit_xor(const std::string &bytes, const char c);

}; // namespace cryptopals
