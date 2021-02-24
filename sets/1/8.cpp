#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

#include "cryptopals/hex.h"
#include "cryptopals/string_utils.h"

int main(int argc, char *argv[])
{
    assert(argc > 1);
    std::ifstream input(argv[1]);
    std::string the_line;
    std::string the_block;
    for (std::string line; std::getline(input, line);)
    {
        std::set<std::string_view> known_blocks;
        for (auto &block :
             cryptopals::blocks(cryptopals::hex_to_bytes(line), 16))
        {
            if (known_blocks.count(block) == 1)
            {
                the_line = line;
                the_block = block;
                break;
            }
            known_blocks.insert(block);
        }
    }
    assert(!the_line.empty());
    assert(!the_block.empty());
    assert(the_block.size() == 16);
    std::cout << "line: " << the_line << '\n';
    std::cout << "block: " << cryptopals::bytes_to_hex(the_block) << '\n';
}
