cmake_minimum_required(VERSION 3.27)
project(compress C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(src)

#add_custom_target(CLION_EXE_DIR=${PROJECT_BINARY_DIR} test COMMAND make)
set(ENV{CLION_EXE_DIR} ${PROJECT_BINARY_DIR})
add_custom_target(test COMMAND make test -C ${CMAKE_SOURCE_DIR})
add_custom_target(compress COMMAND make compress -C ${CMAKE_SOURCE_DIR})
add_custom_target(huffman_tests COMMAND make huffman_tests -C ${CMAKE_SOURCE_DIR})

#add_executable(compress
#        include/huffman_compress.h
#        include/unity.h
#        include/unity_internals.h
#        src/huffman_compress.c
#        src/main.c
#        tests/huffman_tests.c
#        tests/unity.c
#        test.c)
