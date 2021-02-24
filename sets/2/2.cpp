#include <cassert>
#include <iostream>

#include "cryptopals/aes.h"
#include "cryptopals/io.h"

int main(int argc, char *argv[])
{
    assert(argc > 2);
    std::cout << cryptopals::decrypt_aes128_cbc(
                     cryptopals::read_multiline_b64_file(argv[1]), argv[2],
                     std::string(16, '\0')) << "\n";
}
