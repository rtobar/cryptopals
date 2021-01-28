#include <cassert>
#include <iostream>

#include "cryptopals/frequency_analysis.h"

int main(int argc, char *argv[])
{
    assert(argc > 1);
    auto result = cryptopals::best_score_with_single_char_xor(argv[1]);
    std::cout << "key: " << result.key << ", plain text: " << result.plain_text << '\n';
}
