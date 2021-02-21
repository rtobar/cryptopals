#pragma once

#include <string>

namespace cryptopals
{

std::string decrypt_aes128_ecb(const std::string &cipher_text,
                               const std::string &key);

std::string encrypt_aes128_ecb(const std::string &plain_text,
                               const std::string &key);

std::string decrypt_aes128_cbc(const std::string &cipher_text,
                               const std::string &key, const std::string &iv);

} // namespace cryptopals