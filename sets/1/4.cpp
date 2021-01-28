#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

#include "cryptopals/frequency_analysis.h"

int main(int argc, char *argv[])
{
    assert(argc > 1);
    std::ifstream input(argv[1]);
	 std::vector<cryptopals::FrequencyAnalysisResult> results;
    for (std::string line; std::getline(input, line); ) {
        results.push_back(cryptopals::best_score_with_single_char_xor(line));
    }
	 assert(results.size() > 0);
	 std::sort(begin(results), end(results));
	 auto &best_result = results.back();
    std::cout << "key: " << best_result.key << ", plain text: " << best_result.plain_text << '\n';
}
