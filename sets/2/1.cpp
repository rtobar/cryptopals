#include <cassert>
#include <iostream>

#include "cryptopals/padding.h"

int main(int argc, char *argv[])
{
    assert(argc > 2);
    std::cout << cryptopals::add_pkcs7_padding(argv[1], std::atoi(argv[2]))
              << '\n';
}