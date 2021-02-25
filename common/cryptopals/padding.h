#pragma once

#include <string>
#include <string_view>

namespace cryptopals
{

std::string add_pkcs7_padding(std::string_view text, int block_size);

}; // namespace cryptopals
