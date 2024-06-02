#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// TEST(MatrixMultiplicationTest, TestMultiplyMatricesStandard)
// Verifica che la moltiplicazione standard tra matrici funzioni correttamente.
TEST(MatrixMultiplicationTest, TestMultiplyMatricesStandard) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed!";
}

// Verifica il comportamento della funzione quando entrambe le matrici sono vuote.
TEST(MatrixMultiplicationTest, HandlesEmptyMatrices) {
    std::vector<std::vector<int>> A = {};
    std::vector<std::vector<int>> B = {};
    std::vector<std::vector<int>> C;
    multiplyMatrices(A, B, C, 0, 0, 0);
    ASSERT_TRUE(C.empty()) << "Test with empty matrices failed!";
}

// Verifica la corretta moltiplicazione di matrici 1x1.
TEST(MatrixMultiplicationTest, Handles1x1Matrix) {
    std::vector<std::vector<int>> A = {{1}};
    std::vector<std::vector<int>> B = {{2}};
    std::vector<std::vector<int>> C(1, std::vector<int>(1));
    multiplyMatrices(A, B, C, 1, 1, 1);
    EXPECT_EQ(C[0][0], 2) << "Test with 1x1 matrices failed!";
}

// Test per matrici di dimensioni diverse ma compatibili per la moltiplicazione.
TEST(MatrixMultiplicationTest, HandlesDifferentSizes) {
    std::vector<std::vector<int>> A = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> B = {{2, 0}, {1, 2}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2));
    multiplyMatrices(A, B, C, 2, 2, 2);
    ASSERT_EQ(C[0][0], 4) << "Test with different sizes failed!";
    ASSERT_EQ(C[0][1], 4) << "Test with different sizes failed!";
    ASSERT_EQ(C[1][0], 10) << "Test with different sizes failed!";
    ASSERT_EQ(C[1][1], 8) << "Test with different sizes failed!";
}

// Verifica il comportamento della funzione con valori negativi nelle matrici.
TEST(MatrixMultiplicationTest, HandlesNegativeValues) {
    std::vector<std::vector<int>> A = {{-1, -2}, {-3, -4}};
    std::vector<std::vector<int>> B = {{2, 0}, {1, 2}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2));
    multiplyMatrices(A, B, C, 2, 2, 2);
    ASSERT_EQ(C[0][0], 0) << "Test with negative values failed!";
    ASSERT_EQ(C[0][1], -4) << "Test with negative values failed!";
    ASSERT_EQ(C[1][0], -2) << "Test with negative values failed!";
    ASSERT_EQ(C[1][1], -8) << "Test with negative values failed!";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
