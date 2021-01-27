#include <algorithm>
#include <cassert>
#include <functional>

#include "cryptopals/conversions.h"
#include "cryptopals/operations.h"

namespace cryptopals
{

std::string hex_xor(const std::string &hex_string_1,
                    const std::string &hex_string_2)
{
    assert(hex_string_1.size() == hex_string_2.size());
    std::string bytes_1 = hex_to_bytes(hex_string_1);
    std::string bytes_2 = hex_to_bytes(hex_string_2);
    std::string result(bytes_1.size(), 0);
    std::transform(begin(bytes_1), end(bytes_1), begin(bytes_2), begin(result),
                   std::bit_xor<char>{});
    return bytes_to_hex(result);
}

} // namespace cryptopals
