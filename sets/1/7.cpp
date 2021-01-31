#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

#include "cryptopals/io.h"
#include "cryptopals/openssl.h"

int main(int argc, char *argv[])
{
    assert(argc > 2);
    std::cout << cryptopals::decrypt_aes128_ecb(
                     cryptopals::read_multiline_b64_file(argv[1]), argv[2])
              << '\n';
}
