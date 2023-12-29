#ifndef HUFFMAN_H
#define HUFFMAN_H

int compressFile(const char* filePath);
char** HuffmanCodes(char data[], int freq[], int size);
void convertFrequencyTableIntoTwoArrays(int freqTable[], char data[], int freq[], int size);
#endif