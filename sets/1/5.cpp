#include <cassert>
#include <iostream>
#include <sstream>

#include "cryptopals/conversions.h"
#include "cryptopals/operations.h"

int main(int argc, char *argv[])
{
    assert(argc > 2);
    std::string key(argv[2]);
	 auto result = cryptopals::bytes_to_hex(cryptopals::bit_xor(argv[1], key.c_str(), key.size()));
	 // output 75 chars per line
	 for (std::size_t pos = 0; pos < result.size(); pos+= 75)
	 {
		std::cout << result.substr(pos, pos + 75) << '\n';
	 }
}
