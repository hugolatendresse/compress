#include "../include/huffman_compress.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        printf("Usage: ./compress <file> [compression_option]\n");
        return 1;
    }

    const char* filePath = argv[1];
    const char* compressionOption = (argc == 3) ? argv[2] : "huffman";

    if (strcmp(compressionOption, "huffman") != 0) {
        printf("Unsupported compression option: %s\n", compressionOption);
        return 1;
    }

    compressFile(filePath);
    return 0;
}