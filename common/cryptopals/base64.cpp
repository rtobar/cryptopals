#include <algorithm>
#include <array>
#include <cassert>

#include "cryptopals/base64.h"
#include "cryptopals/hex.h"

namespace cryptopals
{

static const std::array<char, 64> base64_table{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

std::string bytes_to_base64(std::string_view bytes)
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

std::string hex_to_base64(std::string_view s)
{
    return bytes_to_base64(hex_to_bytes(s));
}

std::string base64_to_bytes(std::string_view base64_string)
{
    auto b64_to_byte = [](const char c)
    {
        auto pos = std::find(begin(base64_table), end(base64_table), c);
        assert(pos != end(base64_table));
        return static_cast<char>(std::distance(begin(base64_table), pos));
    };
    // main loop
    std::string bytes;
    for (std::size_t pos = 0; pos < base64_string.size() / 4; pos++)
    {
        auto *start = base64_string.data() + pos * 4;
        auto b1 = b64_to_byte(start[0]);
        auto b2 = b64_to_byte(start[1]);
        bytes.push_back((b1 << 2) | (b2 >> 4));

        // padding
        if (start[2] == '=')
        {
            assert(pos + 1 == base64_string.size() / 4);
            assert(start[3] == '=');
            break;
        }
        auto b3 = b64_to_byte(start[2]);
        bytes.push_back((b2 << 4) | (b3 >> 2));

        // padding
        if (start[3] == '=')
        {
            assert(pos + 1 == base64_string.size() / 4);
            break;
        }
        auto b4 = b64_to_byte(start[3]);
        bytes.push_back((b3 << 6) | b4);
    }
    return bytes;
}

} // namespace cryptopals
