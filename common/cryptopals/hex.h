#pragma once

#include <string>
#include <string_view>

namespace cryptopals
{
std::string hex_to_bytes(std::string_view hex_string);
std::string bytes_to_hex(std::string_view bytes);
} // namespace cryptopals
