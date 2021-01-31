#pragma once

#include <string>

namespace cryptopals
{

std::string decrypt_aes128_ecb(const std::string &cipher_text,
                               const std::string &key);

} // namespace cryptopals