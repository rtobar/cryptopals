#pragma once

#include <string>

namespace cryptopals
{

std::string add_pkcs7_padding(const std::string &text, int block_size);

}; // namespace cryptopals
