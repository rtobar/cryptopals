#include <cassert>
#include <iostream>

#include "cryptopals/mt19937.h"

int main(int argc, char *argv[])
{
    assert(argc > 2);
    std::uint16_t key = static_cast<std::uint16_t>(std::atoi(argv[1]));
    std::cout << cryptopals::mt19937::decrypt(
                     cryptopals::mt19937::encrypt(argv[2], key), key)
              << '\n';
}
