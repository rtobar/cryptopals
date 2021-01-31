#include <fstream>

#include "cryptopals/base64.h"
#include "cryptopals/io.h"

namespace cryptopals
{

std::string read_multiline_b64_file(const std::string &filename)
{
    std::ifstream input(filename);
    std::string input_str;
    for (std::string line; std::getline(input, line);)
    {
        input_str += line;
    }
    return base64_to_bytes(input_str);
}

} // namespace cryptopals
