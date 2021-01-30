#pragma once

#include <string>

namespace cryptopals
{
std::string hex_to_bytes(const std::string &hex_string);
std::string bytes_to_hex(const std::string &bytes);
} // namespace cryptopals
