#pragma once

#include <string>
#include <string_view>

namespace cryptopals
{

enum class AESOperationMode
{
    ECB,
    CBC
};

std::string decrypt_aes128_ecb(std::string_view cipher_text,
                               std::string_view key);

std::string encrypt_aes128_ecb(std::string_view plain_text,
                               std::string_view key);

std::string decrypt_aes128_cbc(std::string_view cipher_text,
                               std::string_view key, std::string_view iv);

} // namespace cryptopals