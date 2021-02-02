#include <cassert>
#include <iostream>

#include "cryptopals/openssl.h"

int main(int argc, char *argv[])
{
    assert(argc > 2);
    std::string text = argv[1];
    std::string key = argv[2];
    std::cout << cryptopals::decrypt_aes128_ecb(
                     cryptopals::encrypt_aes128_ecb(text, key), key)
              << '\n';
}
