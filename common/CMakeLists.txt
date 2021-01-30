set(cryptopals_common_sources
  cryptopals/base64.cpp
  cryptopals/base64.h
  cryptopals/frequency_analysis.cpp
  cryptopals/frequency_analysis.h
  cryptopals/hamming.cpp
  cryptopals/hamming.h
  cryptopals/hex.cpp
  cryptopals/hex.h
  cryptopals/xor.cpp
  cryptopals/xor.h
)
add_library(cryptopals_common SHARED ${cryptopals_common_sources})
target_include_directories(cryptopals_common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
