#pragma once

#include <string_view>

namespace cryptopals
{
std::size_t hamming_distance(std::string_view bytes1, std::string_view bytes2);
} // namespace cryptopals
