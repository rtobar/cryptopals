#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>

#include "cryptopals/mt19937.h"

int main(int argc, char *argv[])
{
    assert(argc > 2);
    auto seed = std::atol(argv[1]);
    assert(seed > 0);
    cryptopals::mt19937::set_seed(static_cast<std::uint32_t>(seed));
    auto iterations = std::atoi(argv[2]);
    assert(iterations > 0);
    std::cout << cryptopals::mt19937::rand_signed();
    for (int i = 1; i != iterations; i++)
    {
        std::cout << ' ' << cryptopals::mt19937::rand_signed();
    }
    std::cout << '\n';
}
