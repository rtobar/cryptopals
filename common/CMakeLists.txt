set(cryptopals_common_sources
  cryptopals/aes.cpp
  cryptopals/aes.h
  cryptopals/base64.cpp
  cryptopals/base64.h
  cryptopals/frequency_analysis.cpp
  cryptopals/frequency_analysis.h
  cryptopals/hamming.cpp
  cryptopals/hamming.h
  cryptopals/io.cpp
  cryptopals/io.h
  cryptopals/hex.cpp
  cryptopals/hex.h
  cryptopals/mt19937.cpp
  cryptopals/mt19937.h
  cryptopals/oracle_utils.cpp
  cryptopals/oracle_utils.h
  cryptopals/padding.cpp
  cryptopals/padding.h
  cryptopals/rand.cpp
  cryptopals/rand.h
  cryptopals/string_utils.cpp
  cryptopals/string_utils.h
  cryptopals/xor.cpp
  cryptopals/xor.h
)
add_library(cryptopals_common SHARED ${cryptopals_common_sources})
target_link_libraries(cryptopals_common PRIVATE OpenSSL::Crypto)
target_include_directories(cryptopals_common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
