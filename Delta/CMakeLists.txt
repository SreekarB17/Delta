﻿# CMakeList.txt : CMake project for Delta, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)


# Add source to this project's executable.
add_executable (Delta "Delta.cpp" "include/delta/utility.hpp" "include/delta/memory.hpp" "include/delta/exception.hpp" "include/delta/arithmetic.hpp" "include/delta/algorithm.hpp" "include/delta/string.hpp" "include/delta/iterator.hpp")

# TODO: Add tests and install targets if needed.