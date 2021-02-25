#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace cryptopals
{
std::vector<std::string_view> blocks(std::string_view s, int block_size);

std::vector<std::string> transposed_blocks(std::string_view s, int block_size);

} // namespace cryptopals
