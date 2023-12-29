#include "unity.h"
#include "huffman.h"

void setUp(void) {
    // This is run before EACH test
}

void tearDown(void) {
    // This is run after EACH test
}

void test_compressFile(void) {
    int result = compressFile("test.txt");
    TEST_ASSERT_EQUAL_INT(0, result);
}

void test_HuffmanCodes(void) {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);
    char** actual = HuffmanCodes(data, freq, size);

    TEST_ASSERT_EQUAL_INT("1100", actual[0]);
    TEST_ASSERT_EQUAL_INT("1101", actual[1]);
    TEST_ASSERT_EQUAL_INT("100", actual[2]);
    TEST_ASSERT_EQUAL_INT("101", actual[3]);
    TEST_ASSERT_EQUAL_INT("111", actual[4]);
    TEST_ASSERT_EQUAL_INT("0", actual[5]);

}

// TODO
// void test_decompressFile(void) {
//     int result = decompressFile("test.txt.huff");
//     TEST_ASSERT_EQUAL_INT(0, result);
// }


// TODO test generateHuffmanCodes

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_compressFile);
    RUN_TEST(test_HuffmanCodes);
    return UNITY_END();
}