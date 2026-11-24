cmake_minimum_required(VERSION 3.20)
project(matching_engine C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

add_compile_options(-Wall -Wextra -Wpedantic -Werror)
add_compile_definitions(_POSIX_C_SOURCE=200809L)

enable_testing()

add_executable(test_sanity tests/test_sanity.c)
add_test(NAME sanity COMMAND test_sanity)
