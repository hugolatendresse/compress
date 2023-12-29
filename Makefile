CC = gcc
CFLAGS = -I .

huffman_test: huffman_test.c compress.c unity.c
	$(CC) $(CFLAGS) huffman_test.c compress.c unity.c -o huffman_test
