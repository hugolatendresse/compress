CC = gcc
CFLAGS = -I .

# TODO: create a main.c that refers to huffman_compress and remove the main definition from huffman_compress
huffman_compress: src/main.c src/huffman_compress.c
    $(CC) $(CFLAGS) src/main.c src/huffman_compress.c -o huffman_compress

huffman_tests:  src/huffman_compress.c tests/huffman_test.c tests/unity.c
	$(CC) $(CFLAGS) src/huffman_compress.c tests/huffman_test.c tests/unity.c -o huffman_tests
