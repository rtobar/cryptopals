#pragma once

#include <cstdint>
#include <string>
#include <string_view>

namespace cryptopals
{
namespace mt19937
{

void set_seed(std::uint32_t seed);

std::uint32_t rand();

std::int32_t rand_signed();

std::uint32_t untemper(std::uint32_t value);

template <typename Range> void set_state(const Range &new_state);

std::string encrypt(std::string_view plain_text, std::uint16_t key);
std::string decrypt(std::string_view plain_text, std::uint16_t key);

} // namespace mt19937
} // namespace cryptopals
