#pragma once

#include <string>
#include <string_view>

namespace cryptopals
{

std::string aes_encrypt_with_random_key(std::string_view input);

} // namespace cryptopals
