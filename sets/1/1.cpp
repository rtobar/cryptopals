#include <cassert>
#include <iostream>

#include "cryptopals/conversions.h"

int main(int argc, char *argv[])
{
    assert(argc > 1);
    std::cout << cryptopals::hex_to_base64(argv[1]) << '\n';
}
