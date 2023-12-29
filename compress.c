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

void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void HuffmanCodes(char data[], int freq[], int size) {
    HuffmanTree* minHeap = createHuffmanTree(size);
    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = newNode(data[i], freq[i]);
    }
    minHeap->size = size;
    buildHuffmanTree(minHeap);
    int arr[100], top = 0;
    printCodes(minHeap->array[0], arr, top);
}

