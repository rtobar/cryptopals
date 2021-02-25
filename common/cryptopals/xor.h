#pragma once

#include <string>
#include <string_view>

namespace cryptopals
{
std::string hex_xor(std::string_view hex_string_1,
                    std::string_view hex_string_2);

std::string bit_xor(std::string_view bytes_1, std::string_view bytes_2);

std::string bit_xor(std::string_view bytes_1, const char *key, int key_size);

std::string bit_xor(std::string_view bytes, const char c);

}; // namespace cryptopals
