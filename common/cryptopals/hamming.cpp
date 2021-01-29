#include <bitset>
#include <numeric>

#include "cryptopals/conversions.h"
#include "cryptopals/hamming.h"
#include "cryptopals/xor.h"

namespace cryptopals
{

std::size_t hamming_distance(const std::string &bytes1,
                             const std::string &bytes2)
{
    auto result = bit_xor(bytes1, bytes2);
    auto popcount =
        std::accumulate(begin(result), end(result), static_cast<std::size_t>(0),
                        [](std::size_t popcount, char c)
                        { return popcount + std::bitset<8>(c).count(); });
    return popcount;
}

} // namespace cryptopals
