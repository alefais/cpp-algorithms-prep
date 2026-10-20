cmake_minimum_required(VERSION 3.20)
project(cpp_algorithms_prep LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Helpers in common/, shared by the exercises
add_library(debug_helpers STATIC common/debug.cpp)
target_include_directories(debug_helpers PUBLIC ${CMAKE_SOURCE_DIR})
target_compile_options(debug_helpers PRIVATE -Wall -Wextra -Werror)

# Exercise: two-sum
add_executable(vector_and_target algorithms/01_vectors/vector_and_target.cpp)
target_link_libraries(vector_and_target PRIVATE debug_helpers)
target_compile_options(vector_and_target PRIVATE -Wall -Wextra -Werror)
