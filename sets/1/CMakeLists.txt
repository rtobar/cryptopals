add_executable(1 1.cpp)
add_executable(2 2.cpp)
target_link_libraries(1 PRIVATE cryptopals_common)
target_link_libraries(2 PRIVATE cryptopals_common)
