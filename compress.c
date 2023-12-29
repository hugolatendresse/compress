//  Program that can compress and decompress files, like a simple version of gzip. learn about data compression algorithms.

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the Huffman tree
typedef struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
} Node;

// Define the structure of a Huffman tree
typedef struct HuffmanTree {
    unsigned size;
    unsigned capacity;
    Node **array;
} HuffmanTree;

// Function prototypes
Node* newNode(char data, unsigned freq);
HuffmanTree* createHuffmanTree(unsigned capacity);
void swapNode(Node** a, Node** b);
void minHeapify(HuffmanTree* minHeap, int idx);
int isSizeOne(HuffmanTree* minHeap);
Node* extractMin(HuffmanTree* minHeap);
void insertHuffmanTree(HuffmanTree* minHeap, Node* minHeapNode);
void buildHuffmanTree(HuffmanTree* minHeap);
void printCodes(Node* root, int arr[], int top);
void HuffmanCodes(char data[], int freq[], int size);

// Main function
int main() {
    // Test data
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}

// Implement the functions here
// ...