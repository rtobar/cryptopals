#include <chrono>

#include "cryptopals/time.h"

namespace cryptopals {

int unix_timestamp()
{
    using clock = std::chrono::system_clock;
    return std::chrono::duration_cast<std::chrono::seconds>(
               clock::now().time_since_epoch())
        .count();
}

}  // namespace cryptopals
