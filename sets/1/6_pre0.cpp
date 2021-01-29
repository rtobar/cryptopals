#include <cassert>
#include <iostream>

#include "cryptopals/hamming.h"

int main(int argc, char *argv[])
{
    assert(argc > 2);
    std::cout << cryptopals::hamming_distance(argv[1], argv[2]) << '\n';
}
