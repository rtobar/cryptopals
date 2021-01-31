#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

#include "cryptopals/frequency_analysis.h"
#include "cryptopals/hamming.h"
#include "cryptopals/io.h"
#include "cryptopals/xor.h"

namespace cryptopals
{

std::vector<int> key_size_guesses(const std::string &cipher_text)
{
    std::vector<std::pair<int, int>> normalised_distances;
    // for each size take hamming distance between first 3 pairs of blocks,
    // average and normalise by size
    for (std::size_t size = 2; size != 40; size++)
    {
        auto block1 = cipher_text.substr(size * 0, size);
        auto block2 = cipher_text.substr(size * 1, size);
        auto block3 = cipher_text.substr(size * 2, size);
        auto block4 = cipher_text.substr(size * 3, size);
        auto d1 = hamming_distance(block1, block2);
        auto d2 = hamming_distance(block2, block3);
        auto d3 = hamming_distance(block3, block4);
        normalised_distances.emplace_back((d1 + d2 + d3) / 3 / size, size);
    }
    // keep sizes with the 5 smallest distances
    std::sort(begin(normalised_distances), end(normalised_distances));
    std::vector<int> sizes(5);
    std::transform(begin(normalised_distances),
                   std::next(begin(normalised_distances), 5), begin(sizes),
                   [](auto &kv) { return kv.second; });
    return sizes;
}

std::vector<std::string> transposed_blocks(const std::string &s, int block_size)
{
    std::vector<std::string> blocks(block_size);
    for (std::size_t pos = 0; pos != s.size(); pos++)
    {
        blocks[pos % block_size].push_back(s[pos]);
    }
    return blocks;
}

std::string break_repeating_xor(const std::string &cipher_text)
{
    using KeyGuess = std::pair<int, std::string>;

    std::vector<KeyGuess> key_guesses;
    for (auto key_size_candidate : key_size_guesses(cipher_text))
    {
        auto blocks = transposed_blocks(cipher_text, key_size_candidate);
        std::vector<FrequencyAnalysisResult> results(key_size_candidate);
        std::transform(begin(blocks), end(blocks), begin(results),
                       best_score_with_single_char_xor);

        std::string key;
        int score;
        for (auto result : results)
        {
            key.push_back(result.key);
            score += result.score;
        }
        key_guesses.emplace_back(score, std::move(key));
    }

    std::sort(begin(key_guesses), end(key_guesses), std::greater<KeyGuess>{});
    auto the_key = key_guesses.front().second;
    std::string plain_text =
        bit_xor(cipher_text, the_key.data(), the_key.size());
    return plain_text;
}

} // namespace cryptopals

int main(int argc, char *argv[])
{
    assert(argc > 1);
    std::cout << cryptopals::break_repeating_xor(
                     cryptopals::read_multiline_b64_file(argv[1]))
              << '\n';
}
