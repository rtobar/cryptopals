#pragma once

#include <string>

namespace cryptopals
{
std::string hex_to_bytes(const std::string &s);
std::string bytes_to_base64(const std::string &s);
std::string hex_to_base64(const std::string &s);
} // namespace cryptopals
