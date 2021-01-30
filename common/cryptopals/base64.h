#pragma once

#include <string>

namespace cryptopals
{
std::string bytes_to_base64(const std::string &bytes);
std::string hex_to_base64(const std::string &hex_string);
std::string base64_to_bytes(const std::string &base64_string);
} // namespace cryptopals
