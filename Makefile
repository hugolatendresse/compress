CC = gcc
CFLAGS = -g -I .

# TODO: create a main.c that refers to huffman_compress and remove the main definition from huffman_compress
compress: src/main.c src/huffman_compress.c
	$(CC) $(CFLAGS) src/main.c src/huffman_compress.c -o compress

huffman_tests:  src/huffman_compress.c tests/huffman_tests.c tests/unity.c
	$(CC) $(CFLAGS) src/huffman_compress.c tests/huffman_tests.c tests/unity.c -o huffman_tests

test:  test.c
	$(CC) $(CFLAGS) test.c -o test
