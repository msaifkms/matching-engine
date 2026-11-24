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

# Sanitizers: pass -DSANITIZE=address (ASan + UBSan) or -DSANITIZE=thread (TSan).
set(SANITIZE "" CACHE STRING "Sanitizer to enable: address or thread")
if(SANITIZE STREQUAL "address")
  add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer -fno-sanitize-recover=all)
  add_link_options(-fsanitize=address,undefined)
elseif(SANITIZE STREQUAL "thread")
  add_compile_options(-fsanitize=thread -fno-omit-frame-pointer)
  add_link_options(-fsanitize=thread)
elseif(NOT SANITIZE STREQUAL "")
  message(FATAL_ERROR "Unknown SANITIZE value: ${SANITIZE}")
endif()

enable_testing()

add_executable(test_sanity tests/test_sanity.c)
add_test(NAME sanity COMMAND test_sanity)
