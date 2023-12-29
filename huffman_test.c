#include "unity.h"
#include "compress.h" // Assuming compressFile is declared in this header

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

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_compressFile);
    return UNITY_END();
}