#include <array>
#include <cassert>
#include <iostream>
#include <vector>

#include "cryptopals/mt19937.h"

namespace cryptopals
{
namespace mt19937
{

// Main parameters
constexpr int W = 32;
constexpr int N = 624;

// PRNG state, index is uninitialized
std::array<std::uint32_t, N> state;
int index = N + 1;

// Initialize the generator from a seed
void set_seed(std::uint32_t seed)
{
    constexpr std::uint32_t F = 0x6C078965;
    index = N;
    state[0] = seed;
    for (int i = 1; i != N; i++)
    {
        auto prev_state = state[i - 1];
        state[i] = (prev_state ^ (prev_state >> (W - 2))) * F + i;
    }
}

template <typename Range> void set_state(const Range &new_state)
{
    assert(new_state.size() == N);
    std::copy(new_state.begin(), new_state.end(), state.begin());
    index = 0;
};

template void set_state<std::vector<std::uint32_t>>(
    const std::vector<std::uint32_t> &new_state);

static void twist()
{
    constexpr std::uint32_t M = 397;
    constexpr std::uint32_t R = 31;
    constexpr std::uint32_t A = 0x9908B0DF;
    constexpr std::uint32_t lower_mask = (1U << R) - 1;
    constexpr std::uint32_t upper_mask = ~lower_mask;

    for (int i = 0; i != N; i++)
    {
        auto next_state = state[(i + 1) % N];
        auto mid_state = state[(i + M) % N];
        auto x = (state[i] & upper_mask) | (next_state & lower_mask);
        state[i] = (A * (next_state & 0x1)) ^ (x >> 1) ^ mid_state;
    }
    index = 0;
}

constexpr std::uint32_t U = 11;
constexpr std::uint32_t S = 7;
constexpr std::uint32_t B = 0x9D2C5680;
constexpr std::uint32_t T = 15;
constexpr std::uint32_t C = 0xEFC60000;
constexpr std::uint32_t L = 18;

std::uint32_t temper(std::uint32_t x)
{
    x ^= x >> U;
    x ^= (x << S) & B;
    x ^= (x << T) & C;
    x ^= x >> L;
    return x;
}

std::uint32_t untemper(std::uint32_t value)
{
    value ^= value >> L;
    value ^= (value << T) & C;

    auto x = value;
    for (int i = 0; i != 5; i++)
    {
        x <<= S;
        x = value ^ (x & B);
    }
    value = x;

    for (int i = 0; i != 2; i++)
    {
        x >>= U;
        x ^= value;
    };
    value = x;
    return value;
}

std::uint32_t rand()
{
    if (index >= N)
    {
        if (index > N)
        {
            set_seed(53);
        }
        twist();
    }
    return temper(state[index++]);
}

std::int32_t rand_signed()
{
    auto value = rand();
    return *reinterpret_cast<std::int32_t *>(&value);
}

} // namespace mt19937
} // namespace cryptopals
