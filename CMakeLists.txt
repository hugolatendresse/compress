cmake_minimum_required(VERSION 3.27)
project(compress C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(src)

add_executable(compress
        include/huffman_compress.h
        include/unity.h
        include/unity_internals.h
        src/huffman_compress.c
        src/main.c
        tests/huffman_tests.c
        tests/unity.c
        test.c)
