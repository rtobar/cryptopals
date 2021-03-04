#include <cassert>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include "cryptopals/mt19937.h"
#include "cryptopals/rand.h"

static int unix_timestamp()
{
    using clock = std::chrono::system_clock;
    return std::chrono::duration_cast<std::chrono::seconds>(
               clock::now().time_since_epoch())
        .count();
}

static void rand_sleep(int max)
{
    std::this_thread::sleep_for(
        std::chrono::milliseconds(cryptopals::generate_random_int(0, max)));
}

int main()
{
    const int max_sleep = 1000;
    rand_sleep(max_sleep);
    auto seed = unix_timestamp();
    cryptopals::mt19937::set_seed(static_cast<std::uint32_t>(seed));
    rand_sleep(max_sleep);
    auto value = cryptopals::mt19937::rand();

    // Go and make an educated guess, I guess...
    auto now = unix_timestamp();
    for (int i = 0; i != max_sleep * 10; i++)
    {
        auto potential_seed = now - i;
        cryptopals::mt19937::set_seed(
            static_cast<std::uint32_t>(potential_seed));
        auto guess_value = cryptopals::mt19937::rand();
        if (guess_value == value)
        {
            return potential_seed != seed;
        }
    }
    return 1;
}
