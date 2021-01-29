#include <algorithm>
#include <cassert>
#include <functional>
#include <numeric>

#include "cryptopals/conversions.h"
#include "cryptopals/xor.h"

namespace cryptopals
{

std::string hex_xor(const std::string &hex_string_1,
                    const std::string &hex_string_2)
{
    assert(hex_string_1.size() == hex_string_2.size());
    auto result =
        bit_xor(hex_to_bytes(hex_string_1), hex_to_bytes(hex_string_2));
    return bytes_to_hex(result);
}

std::string bit_xor(const std::string &bytes_1, const std::string &bytes_2)
{
    assert(bytes_1.size() == bytes_2.size());
    std::string result(bytes_1.size(), 0);
    std::transform(begin(bytes_1), end(bytes_1), begin(bytes_2), begin(result),
                   std::bit_xor<char>{});
    return result;
}

std::string bit_xor(const std::string &bytes, const char *key, int key_size)
{
    std::string result(bytes.size(), 0);
    auto key_xor = [i = 0, key, key_size](char c) mutable
    { return c ^ key[i++ % key_size]; };
    std::transform(begin(bytes), end(bytes), begin(result), key_xor);
    return result;
}

std::string bit_xor(const std::string &bytes, const char c)
{
    std::string result(bytes.size(), 0);
    std::transform(begin(bytes), end(bytes), begin(result),
                   [&](char b) { return c ^ b; });
    return result;
}

} // namespace cryptopals
