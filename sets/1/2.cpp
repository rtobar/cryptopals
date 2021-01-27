#include <cassert>
#include <iostream>

#include "cryptopals/operations.h"

int main(int argc, char *argv[])
{
    assert(argc > 2);
    std::cout << cryptopals::hex_xor(argv[1], argv[2]) << '\n';
}
