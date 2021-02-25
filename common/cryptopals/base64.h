#pragma once

#include <string>
#include <string_view>

namespace cryptopals
{
std::string bytes_to_base64(std::string_view bytes);
std::string hex_to_base64(std::string_view hex_string);
std::string base64_to_bytes(std::string_view base64_string);
} // namespace cryptopals
