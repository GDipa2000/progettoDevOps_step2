#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>


// ######################### Source code of multiplyMatrices in src/matrix_mult

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

   ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((((";
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

// Verifica il comportamento della funzione con valori negativi nelle matrici.
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
   
   ASSERT_EQ(C[0][0], 0) << "Test with negative values failed!";
   ASSERT_EQ(C[0][1], -4) << "Test with negative values failed!";
   ASSERT_EQ(C[1][0], -2) << "Test with negative values failed!";
   ASSERT_EQ(C[1][1], -8) << "Test with negative values failed!";
}

/*DA QUA AGGIUNTI NUOVI TEST*/

// Verifica il comportamento della funzione con matrici di dimensioni diverse.
TEST(MatrixMultiplicationTest, HandlesDifferentDimensions) {
   std::vector<std::vector<int>> A = {
       {1, 2, 3}, 
       {4, 5, 6}
   };
   std::vector<std::vector<int>> B = {
       {7, 8}, 
       {9, 10}, 
       {11, 12}
   };
   std::vector<std::vector<int>> C(2, std::vector<int>(2));
   
   multiplyMatrices(A, B, C, 2, 3, 2);
   
   ASSERT_EQ(C[0][0], 58) << "Test with different dimensions failed!";
   ASSERT_EQ(C[0][1], 64) << "Test with different dimensions failed!";
   ASSERT_EQ(C[1][0], 139) << "Test with different dimensions failed!";
   ASSERT_EQ(C[1][1], 154) << "Test with different dimensions failed!";
}

// Verifica il comportamento della funzioni per matrici grandi.
TEST(MatrixMultiplicationTest, HandlesLargeMatrices) {
   std::vector<std::vector<int>> A(100, std::vector<int>(100, 1));
   std::vector<std::vector<int>> B(100, std::vector<int>(100, 1));
   std::vector<std::vector<int>> C(100, std::vector<int>(100, 0));
   
   multiplyMatrices(A, B, C, 100, 100, 100);
   
   for (int i = 0; i < 100; i++) {
       for (int j = 0; j < 100; j++) {
           ASSERT_EQ(C[i][j], 100) << "Test with large matrices failed!";
       }
   }
}

// Verifica il comportamento per matrice identità.
TEST(MatrixMultiplicationTest, HandlesIdentityMatrix) {
   std::vector<std::vector<int>> A = {
       {1, 0}, 
       {0, 1}
   };
   std::vector<std::vector<int>> B = {
       {1, 2}, 
       {3, 4}
   };
   std::vector<std::vector<int>> C(2, std::vector<int>(2));
   
   multiplyMatrices(A, B, C, 2, 2, 2);
   
   ASSERT_EQ(C[0][0], 1) << "Test with identity matrix failed!";
   ASSERT_EQ(C[0][1], 2) << "Test with identity matrix failed!";
   ASSERT_EQ(C[1][0], 3) << "Test with identity matrix failed!";
   ASSERT_EQ(C[1][1], 4) << "Test with identity matrix failed!";
}

// Verifica il comportamento della funzione per matrici incompatibili.
TEST(MatrixMultiplicationTest, HandlesIncompatibleMatrices) {
   std::vector<std::vector<int>> A = {
       {1, 2}, 
       {3, 4}
   };
   std::vector<std::vector<int>> B = {
       {1, 2}, 
       {3, 4}, 
       {5, 6}
   };
   std::vector<std::vector<int>> C;
   
   ASSERT_DEATH(multiplyMatrices(A, B, C, 2, 2, 3), "Assertion failed") << "Test with incompatible matrices failed!";
}

// Verifica il comportamento della funzione per metrice zero.
TEST(MatrixMultiplicationTest, HandlesZeroMatrix) {
   std::vector<std::vector<int>> A = {
       {0, 0}, 
       {0, 0}
   };
   std::vector<std::vector<int>> B = {
       {0, 0}, 
       {0, 0}
   };
   std::vector<std::vector<int>> C(2, std::vector<int>(2));
   
   multiplyMatrices(A, B, C, 2, 2, 2);
   
   ASSERT_EQ(C[0][0], 0) << "Test with zero matrix failed!";
   ASSERT_EQ(C[0][1], 0) << "Test with zero matrix failed!";
   ASSERT_EQ(C[1][0], 0) << "Test with zero matrix failed!";
   ASSERT_EQ(C[1][1], 0) << "Test with zero matrix failed!";
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}