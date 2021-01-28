cmake_minimum_required(VERSION 3.1)
project(cryptopals VERSION 1.0.0 LANGUAGES CXX)

include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

function(add_challenge challenge_number)
  cmake_parse_arguments(challenge "" "" "INPUT;OUTPUT" ${ARGV})
  get_filename_component(set_number ${CMAKE_CURRENT_SOURCE_DIR} NAME)
  set(exec_name set_${set_number}_challenge_${challenge_number})

  add_executable(${exec_name} ${challenge_number}.cpp)
  target_link_libraries(${exec_name} PRIVATE cryptopals_common)
  set_target_properties(${exec_name}
    PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
  )

  string (REPLACE ";" " " challenge_INPUT_STR "${challenge_INPUT}")
  add_test(NAME test_${exec_name}
    COMMAND ${PROJECT_SOURCE_DIR}/cmake/run_and_compare
	 $<TARGET_FILE:${exec_name}> "${challenge_INPUT_STR}" "${challenge_OUTPUT}"
  )
endfunction()

add_subdirectory(common)
add_subdirectory(sets)