#include <iostream>
#include "matrix.h"

int main() {
    try {
        // Создаем тестовые матрицы
        Matrix A = create_matrix(2, 2);
        Matrix B = create_matrix(2, 2);
        Matrix F = create_matrix(1, 2);
        Matrix G = create_matrix(1, 2);

        // Заполняем данными
        A.data[0][0] = 1; A.data[0][1] = 2;
        A.data[1][0] = 3; A.data[1][1] = 4;

        B.data[0][0] = 5; B.data[0][1] = 6;
        B.data[1][0] = 7; B.data[1][1] = 8;

        F.data[0][0] = 9; F.data[0][1] = 10;
        G.data[0][0] = 11; G.data[0][1] = 12;


        std::cout << "Matrix A:" << std::endl;
        print_matrix(A);

        std::cout << "\nMatrix B:" << std::endl;
        print_matrix(B);

        // Тестируем сложение
        Matrix C = matrix_add(A, B);
        std::cout << "\nA + B:" << std::endl;
        print_matrix(C);

        // Тестируем умножение
        Matrix D = matrix_multiply(A, B);
        std::cout << "\nA * B:" << std::endl;
        print_matrix(D);

        // Тестируем транспонирование
        Matrix E = matrix_transpose(A);
        std::cout << "\nTranspose of A:" << std::endl;
        print_matrix(E);
        std::cout << "\nMatrix F:" << std::endl;
        print_matrix(F);

        std::cout << "\nMatrix G:" << std::endl;
        print_matrix(G);
        // Тестируем индивидуальное задание - сумму элементов
        Matrix H = matrix_vstack(F, G);
        std::cout << "\nVertical stack of F and G:" << std::endl;
        print_matrix(H);

        // Освобождаем память (КАЖДУЮ МАТРИЦУ ТОЛЬКО ОДИН РАЗ!)
        free_matrix(A);
        free_matrix(B);
        free_matrix(C);
        free_matrix(D);
        free_matrix(E);
        free_matrix(F);
        free_matrix(G);
        free_matrix(H);


        std::cout << "\nAll operations completed successfully!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
