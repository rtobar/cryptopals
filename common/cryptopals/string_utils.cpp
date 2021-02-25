#include "cryptopals/string_utils.h"

namespace cryptopals
{
std::vector<std::string_view> blocks(std::string_view s, int block_size)
{
    std::vector<std::string_view> blocks;
    std::size_t pos;
    for (pos = 0; pos != s.size() / block_size; pos++)
    {
        blocks.emplace_back(s.substr(pos * block_size, block_size));
    }
    pos *= block_size;
    ;
    if (pos < s.size())
    {
        blocks.emplace_back(s.substr(pos, s.size() - pos));
    }
    return blocks;
}

std::vector<std::string> transposed_blocks(std::string_view s, int block_size)
{
    std::vector<std::string> blocks(block_size);
    for (std::size_t pos = 0; pos != s.size(); pos++)
    {
        blocks[pos % block_size].push_back(s[pos]);
    }
    return blocks;
}

} // namespace cryptopals
