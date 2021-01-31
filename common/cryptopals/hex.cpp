#include <algorithm>
#include <array>
#include <cassert>
#include <string>

#include "cryptopals/hex.h"

namespace cryptopals
{

static bool is_hex_digit(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
           (c >= 'A' && c <= 'F');
}

static char hex_to_decimal(char c)
{
    assert(is_hex_digit(c));
    if (c <= '9')
        return c - '0';
    if (c <= 'f')
        return (c - 'a') + 10;
    return (c - 'A') + 10;
}

static char decimal_to_hex(char c)
{
    if (c < 10)
        return c + '0';
    return c - 10 + 'a';
}

std::string hex_to_bytes(const std::string &s)
{
    assert(s.size() % 2 == 0);
    std::string bytes;
    for (std::size_t pos = 0; pos < s.size(); pos += 2)
    {
        bytes.push_back(hex_to_decimal(s[pos]) * 16 +
                        hex_to_decimal(s[pos + 1]));
    }
    return bytes;
}

std::string bytes_to_hex(const std::string &bytes)
{
    std::string hex;
    for (auto byte : bytes)
    {
        hex.push_back(decimal_to_hex(static_cast<unsigned char>(byte) / 16));
        hex.push_back(decimal_to_hex(static_cast<unsigned char>(byte) % 16));
    }
    return hex;
}

} // namespace cryptopals
