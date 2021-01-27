set(cryptopals_common_sources
  cryptopals/conversions.cpp
  cryptopals/conversions.h
  cryptopals/operations.cpp
  cryptopals/operations.h
)
add_library(cryptopals_common SHARED ${cryptopals_common_sources})
target_include_directories(cryptopals_common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
