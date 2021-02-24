#include <random>

#include "cryptopals/aes.h"
#include "cryptopals/oracle_utils.h"
#include "cryptopals/rand.h"

namespace cryptopals
{

std::string aes_encrypt_with_random_key(std::string_view input)
{
    std::random_device device{};
    std::default_random_engine engine{device()};
    std::uniform_int_distribution<int> mode_decision_distro{0, 1};

    auto key = generate_random_string(16);
    if (mode_decision_distro(engine) == 0)
    {
        return decrypt_aes128_ecb(input, key);
    }
    auto iv = generate_random_string(16);
    return decrypt_aes128_cbc(input, key, iv);
}

} // namespace cryptopals
