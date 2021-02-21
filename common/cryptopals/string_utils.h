#pragma once

#include <string>
#include <vector>

namespace cryptopals
{
std::vector<std::string> blocks(const std::string &s, int block_size);

std::vector<std::string> transposed_blocks(const std::string &s,
                                           int block_size);

} // namespace cryptopals
