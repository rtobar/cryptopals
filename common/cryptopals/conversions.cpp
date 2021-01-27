#include <array>
#include <cassert>
#include <string>

#include "cryptopals/conversions.h"

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

static const std::array<char, 64> base64_table{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

std::string bytes_to_base64(const std::string &bytes)
{
    std::string b64;
    auto push_base64_symbol = [&](char c)
    {
        assert(c < 64);
        b64.push_back(base64_table[c]);
    };
    auto *data = bytes.data();
    // main loop
    std::size_t pos = 0;
    for (; pos < bytes.size() / 3; pos++)
    {
        auto *start = data + pos * 3;
        push_base64_symbol(start[0] >> 2);
        push_base64_symbol((start[0] & 0x03) << 4 | start[1] >> 4);
        push_base64_symbol((start[1] & 0x0f) << 2 | start[2] >> 6);
        push_base64_symbol(start[2] & 0x3f);
    }
    // padding
    pos *= 3;
    if (bytes.size() - pos == 2)
    {
        auto *start = data + pos;
        push_base64_symbol(start[0] >> 2);
        push_base64_symbol((start[0] & 0x03) << 4 | start[1] >> 4);
        push_base64_symbol((start[1] & 0x0f) << 2);
        b64.push_back('=');
    }
    else if (bytes.size() - pos == 1)
    {
        auto *start = data + pos * 3;
        push_base64_symbol(start[0] >> 2);
        push_base64_symbol((start[0] & 0x03) << 4);
        b64.push_back('=');
        b64.push_back('=');
    }
    return b64;
}

std::string hex_to_base64(const std::string &s)
{
    return bytes_to_base64(hex_to_bytes(s));
}

} // namespace cryptopals
