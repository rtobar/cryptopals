#include <algorithm>
#include <iostream>
#include <string>
#include <thread>

#include "cryptopals/mt19937.h"
#include "cryptopals/rand.h"
#include "cryptopals/time.h"

int main()
{
    cryptopals::mt19937::set_seed(
        static_cast<std::uint32_t>(cryptopals::unix_timestamp()));

    // generate initial values and untumper them
    std::vector<std::uint32_t> values(624);
    std::vector<std::uint32_t> untempered_state(624);
    std::generate(values.begin(), values.end(), cryptopals::mt19937::rand);
    std::transform(values.begin(), values.end(), untempered_state.begin(),
                   cryptopals::mt19937::untemper);

    // set state, regenerate values and check they are the same as before
    cryptopals::mt19937::set_state(untempered_state);
    std::vector<std::uint32_t> new_values(624);
    std::generate(new_values.begin(), new_values.end(),
                  cryptopals::mt19937::rand);
    return values != new_values;
}
