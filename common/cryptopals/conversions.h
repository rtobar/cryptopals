#pragma once

#include <string>

namespace cryptopals
{
std::string hex_to_bytes(const std::string &hex_string);
std::string bytes_to_hex(const std::string &bytes);
std::string bytes_to_base64(const std::string &bytes);
std::string hex_to_base64(const std::string &hex_string);
} // namespace cryptopals
