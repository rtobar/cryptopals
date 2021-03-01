#pragma once

#include <cstdint>

namespace cryptopals
{
namespace mt19937
{

void set_seed(std::uint32_t seed);

std::uint32_t rand();

std::int32_t rand_signed();

} // namespace mt19937
} // namespace cryptopals
