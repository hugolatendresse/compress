#CC = gcc
#CFLAGS = -g -I .

## TODO: create a main.c that refers to huffman_compress and remove the main definition from huffman_compress
compress: src/main.c src/huffman_compress.c
	$(CC) $(CFLAGS) src/main.c src/huffman_compress.c -o compress

huffman_tests:  src/huffman_compress.c tests/huffman_tests.c tests/unity.c
	$(CC) $(CFLAGS) src/huffman_compress.c tests/huffman_tests.c tests/unity.c -o huffman_tests

test:
	$(CC) $(CFLAGS) test.c -o test
	$(CC) $(CFLAGS) test2.c -o test2

#all:
##	echo "Compiling: `$(CLION_EXE_DIR)/test` from Makefile in compress project"
##	gcc -g -o $(CLION_EXE_DIR)/test test.c -lpthread
#	gcc -g -o test test.c -lpthread
#	gcc -g -o test2 test2.c -lpthread
#
clean:
	del /F /Q test.exe
	del /F /Q test2.exe
