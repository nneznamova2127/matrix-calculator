#include <gtest/gtest.h>
#include "matrix.h"

TEST(MatrixTest, CreateAndFree) {
    Matrix m = create_matrix(2, 2);
    EXPECT_EQ(m.rows, 2);
    EXPECT_EQ(m.cols, 2);
    EXPECT_NE(m.data, nullptr);
    free_matrix(m);
}

TEST(MatrixTest, InvalidSize) {
    EXPECT_THROW(create_matrix(-1, 2), std::invalid_argument);
}

TEST(MatrixTest, MatrixAddition) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);

    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;

    B.data[0][0] = 5; B.data[0][1] = 6;
    B.data[1][0] = 7; B.data[1][1] = 8;

    Matrix C = matrix_add(A, B);
    EXPECT_EQ(C.data[0][0], 6);
    EXPECT_EQ(C.data[0][1], 8);
    EXPECT_EQ(C.data[1][0], 10);
    EXPECT_EQ(C.data[1][1], 12);

    free_matrix(A);
    free_matrix(B);
    free_matrix(C);
}

TEST(MatrixTest, MatrixMultiplication) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);

    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;

    B.data[0][0] = 5; B.data[0][1] = 6;
    B.data[1][0] = 7; B.data[1][1] = 8;

    Matrix C = matrix_multiply(A, B);
    EXPECT_EQ(C.data[0][0], 19);
    EXPECT_EQ(C.data[0][1], 22);
    EXPECT_EQ(C.data[1][0], 43);
    EXPECT_EQ(C.data[1][1], 50);

    free_matrix(A);
    free_matrix(B);
    free_matrix(C);
}

TEST(MatrixTest, MatrixTranspose) {
    Matrix A = create_matrix(2, 3);

    A.data[0][0] = 1; A.data[0][1] = 2; A.data[0][2] = 3;
    A.data[1][0] = 4; A.data[1][1] = 5; A.data[1][2] = 6;

    Matrix T = matrix_transpose(A);
    EXPECT_EQ(T.rows, 3);
    EXPECT_EQ(T.cols, 2);
    EXPECT_EQ(T.data[0][0], 1);
    EXPECT_EQ(T.data[0][1], 4);
    EXPECT_EQ(T.data[1][0], 2);
    EXPECT_EQ(T.data[1][1], 5);
    EXPECT_EQ(T.data[2][0], 3);
    EXPECT_EQ(T.data[2][1], 6);

    free_matrix(A);
    free_matrix(T);
}

TEST(MatrixTest, MatrixSum) {
    Matrix A = create_matrix(2, 2);

    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;

    double sum = matrix_sum(A);
    EXPECT_EQ(sum, 10); // 1 + 2 + 3 + 4 = 10

    free_matrix(A);
}

TEST(MatrixTest, AdditionSizeMismatch) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(3, 3);

    EXPECT_THROW(matrix_add(A, B), std::invalid_argument);

    free_matrix(A);
    free_matrix(B);
}

TEST(MatrixTest, MultiplicationSizeMismatch) {
    Matrix A = create_matrix(2, 3);
    Matrix B = create_matrix(2, 3); // Несовместимые размеры

    EXPECT_THROW(matrix_multiply(A, B), std::invalid_argument);

    free_matrix(A);
    free_matrix(B);
}

// tests/test_matrix.cpp
TEST(MatrixTest, MatrixVStack) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);

    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;

    B.data[0][0] = 5; B.data[0][1] = 6;
    B.data[1][0] = 7; B.data[1][1] = 8;

    Matrix C = matrix_vstack(A, B);

    // Проверяем размеры
    EXPECT_EQ(C.rows, 4);
    EXPECT_EQ(C.cols, 2);

    // Проверяем содержимое
    EXPECT_EQ(C.data[0][0], 1); EXPECT_EQ(C.data[0][1], 2);  // A[0]
    EXPECT_EQ(C.data[1][0], 3); EXPECT_EQ(C.data[1][1], 4);  // A[1]
    EXPECT_EQ(C.data[2][0], 5); EXPECT_EQ(C.data[2][1], 6);  // B[0]
    EXPECT_EQ(C.data[3][0], 7); EXPECT_EQ(C.data[3][1], 8);  // B[1]

    free_matrix(A);
    free_matrix(B);
    free_matrix(C);
}

TEST(MatrixTest, MatrixVStackInvalid) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 3); // Разное количество столбцов

    EXPECT_THROW(matrix_vstack(A, B), std::invalid_argument);

    free_matrix(A);
    free_matrix(B);
}
