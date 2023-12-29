//  Program that can compress and decompress files, like a simple version of gzip. learn about data compression algorithms.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
} Node;

typedef struct HuffmanTree {
    unsigned size;
    unsigned capacity;
    Node **array;
} HuffmanTree;

int compressFile(const char* filePath);
Node* newNode(char data, unsigned freq);
HuffmanTree* createHuffmanTree(unsigned capacity);
void swapNode(Node** a, Node** b);
void minHeapify(HuffmanTree* minHeap, int idx);
int isSizeOne(HuffmanTree* minHeap);
Node* extractMin(HuffmanTree* minHeap);
void insertHuffmanTree(HuffmanTree* minHeap, Node* minHeapNode);
void buildHuffmanTree(HuffmanTree* minHeap);
char** printCodes(Node* root, int arr[], int top);
char** HuffmanCodes(char data[], int freq[], int size);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./compress <file>\n");
        return 1;
    }
    compressFile(argv[1]);
    return 0;
}

int compressFile(const char* filePath) {
    // Open file
    FILE* file = fopen(filePath, "r");
    if (!file) {
        printf("Could not open file: %s\n", filePath);
        return;
    }

    // Create a frequency table
    int freq[256] = {0};
    char c;
    while ((c = fgetc(file)) != EOF) {
        freq[(unsigned char)c]++;
    }

    // Build the Huffman tree and code table
    HuffmanCodes(freq, 256, 256);
    fclose(file);

    // Open the file for writing
    char* outFilePath = malloc(strlen(filePath) + 5); // +5 for ".huff" and null terminator
    strcpy(outFilePath, filePath);
    strcat(outFilePath, ".huff");
    FILE* outFile = fopen(outFilePath, "w");
    if (!outFile) {
        printf("Could not open file: %s\n", outFilePath);
        free(outFilePath);
        return;
    }

    // TODO Compress the file and write to outFile
    

    // Close the outFile and free the memory
    fclose(outFile);
    free(outFilePath);
}

Node* newNode(char data, unsigned freq) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

HuffmanTree* createHuffmanTree(unsigned capacity) {
    HuffmanTree* minHeap = (HuffmanTree*)malloc(sizeof(HuffmanTree));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (Node**)malloc(minHeap->capacity * sizeof(Node*));
    return minHeap;
}

void swapNode(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(HuffmanTree* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
        smallest = left;
    }
    
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
        smallest = right;
    }
    
    if (smallest != idx) {
        swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(HuffmanTree* minHeap) {
    return (minHeap->size == 1);
}

Node* extractMin(HuffmanTree* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertHuffmanTree(HuffmanTree* minHeap, Node* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildHuffmanTree(HuffmanTree* minHeap) {
    Node* left, *right, *top;
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertHuffmanTree(minHeap, top);
    }
}

char** printCodes(Node* root, int arr[], int top, char** codes, int* index) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, codes, index);
    }
    
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, codes, index);
    }
    
    if (!root->left && !root->right) {
        codes[*index] = malloc(top + 1);
        for (int i = 0; i < top; ++i) {
            codes[*index][i] = arr[i] ? '1' : '0';
        }
        codes[*index][top] = '\0';
        (*index)++;
    }

    return codes;
}

char** HuffmanCodes(char data[], int freq[], int size) {
    // Create a min heap & inserts all characters of data[]
    HuffmanTree* minHeap = createAndBuildMinHeap(data, freq, size);

    // Build Huffman Tree
    buildHuffmanTree(minHeap);

    // Print Huffman codes using the Huffman tree built above
    int arr[MAX_TREE_HT], top = 0;

    // Allocate memory for the codes array
    char** codes = malloc(size * sizeof(char*));
    int index = 0;

    printCodes(minHeap->array[0], arr, top, codes, &index);

    // Return the codes array
    return codes;
}
