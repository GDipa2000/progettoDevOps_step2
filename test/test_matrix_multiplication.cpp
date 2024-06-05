#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <chrono>


// Test per verificare la corretta moltiplicazione di due matrici 2x3 e 3x2.
// Risultato atteso: [[58, 64], [139, 154]]
TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
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

// Test per gestire il caso in cui entrambe le matrici sono vuote.
// Risultato atteso: []
TEST(MatrixMultiplicationTest, HandlesEmptyMatrices) {
   std::vector<std::vector<int>> A = {};
   std::vector<std::vector<int>> B = {};
   std::vector<std::vector<int>> C;
   multiplyMatrices(A, B, C, 0, 0, 0);
   ASSERT_TRUE(C.empty()) << "Test with empty matrices failed!";
}

// Test per la moltiplicazione di due matrici 1x1.
// Risultato atteso: [[2]]
TEST(MatrixMultiplicationTest, Handles1x1Matrix) {
   std::vector<std::vector<int>> A = {{1}};
   std::vector<std::vector<int>> B = {{2}};
   std::vector<std::vector<int>> C(1, std::vector<int>(1));
   multiplyMatrices(A, B, C, 1, 1, 1);
   EXPECT_EQ(C[0][0], 2) << "Test with 1x1 matrices failed!";
}

// Test per matrici di dimensioni diverse ma compatibili per la moltiplicazione.
// Risultato atteso: [[4, 4], [10, 8]]
TEST(MatrixMultiplicationTest, HandlesDifferentSizes) {
   std::vector<std::vector<int>> A = {
       {1, 2}, 
       {3, 4}
   };
   std::vector<std::vector<int>> B = {
       {2, 0}, 
       {1, 2}
   };
   std::vector<std::vector<int>> C(2, std::vector<int>(2));

   multiplyMatrices(A, B, C, 2, 2, 2);

   ASSERT_EQ(C[0][0], 4) << "Test with different sizes failed!";
   ASSERT_EQ(C[0][1], 4) << "Test with different sizes failed!";
   ASSERT_EQ(C[1][0], 10) << "Test with different sizes failed!";
   ASSERT_EQ(C[1][1], 8) << "Test with different sizes failed!";
}
// Test per verificare la moltiplicazione di matrici contenenti valori negativi.
// Risultato atteso: [[-4, -4], [-10, -8]]
TEST(MatrixMultiplicationTest, HandlesNegativeValues) {
   std::vector<std::vector<int>> A = {
       {-1, -2}, 
       {-3, -4}
   };
   std::vector<std::vector<int>> B = {
       {2, 0},
       {1, 2}
   };
   std::vector<std::vector<int>> C(2, std::vector<int>(2));
   
   multiplyMatrices(A, B, C, 2, 2, 2);
   
   ASSERT_EQ(C[0][0], -4) << "Test with negative values failed!";
   ASSERT_EQ(C[0][1], -4) << "Test with negative values failed!";
   ASSERT_EQ(C[1][0], -10) << "Test with negative values failed!";
   ASSERT_EQ(C[1][1], -8) << "Test with negative values failed!";
}


// Test di performance per valutare il tempo di esecuzione della funzione con matrici di grandi dimensioni.
// Questo test è importante per l'high performance computing dove il tempo di esecuzione è critico.
// Il risultato atteso è che il tempo di esecuzione sia entro un limite ragionevole, qui presunto meno di 10000 ms.
TEST(MatrixMultiplicationTest, PerformanceTest) {
    int size = 500;  // Grande dimensione per test di performance
    std::vector<std::vector<int>> A(size, std::vector<int>(size, 1));
    std::vector<std::vector<int>> B(size, std::vector<int>(size, 2));
    std::vector<std::vector<int>> C(size, std::vector<int>(size, 0));

    auto start = std::chrono::high_resolution_clock::now();
    multiplyMatrices(A, B, C, size, size, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;

    std::cout << "Performance Test: Elapsed time is " << elapsed.count() << " ms\n";
    ASSERT_TRUE(elapsed.count() < 10000);  // Il test passa se il tempo è minore di 10000 ms.
}


int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
