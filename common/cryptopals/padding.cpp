#include <string>

#include "cryptopals/padding.h"

namespace cryptopals
{

std::string add_pkcs7_padding(std::string_view text, int block_size)
{
    auto padding = block_size - (text.size() % block_size);
    std::string padded_text{text};
    padded_text.insert(padded_text.end(), padding, static_cast<char>(padding));
    return padded_text;
}

}; // namespace cryptopals
