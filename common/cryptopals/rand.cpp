#include <algorithm>
#include <random>

#include "cryptopals/rand.h"

namespace cryptopals
{

std::string generate_random_string(unsigned int length)
{
    std::default_random_engine engine{std::random_device{}()};
    std::uniform_int_distribution<char> distro;
    std::string key(length, '\0');
    std::generate(key.begin(), key.end(), [&]() { return distro(engine); });
    return key;
}

} // namespace cryptopals
