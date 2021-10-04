#include <iostream>
#include <list>
#include <array>
#include <memory>

#include "Matrix.h"
#include "Iterator.h"


template <typename T>
void addNumber(std::list<T>& d) {
    T temp = 0;
    for (const auto& i : d) {
        temp += i;
    }
    d.push_back(temp / d.size());
}


void task1() {
    std::list<int> digits {-1, -5, 4, 88, 49, 17, 60};
    addNumber(digits);
    for (auto it = std::prev(digits.end()); it != digits.end(); ++it) {
        std::cout << *it << std::endl;
    }
    for (const auto& i : digits) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

int main() {
//1.
    task1();

//2.
    try {
        Matrix m1(3, 3);
        std::cout << m1;
    }
    catch (std::exception& ex) {
        std::cout << ex.what();
    }

    const int sizeMatrix = 3;
    std::vector<std::vector<int>> matrix(sizeMatrix);
    for (auto& i : matrix) {
        i.resize(sizeMatrix);
    }
    std::vector<int> randomMatrix {3, 5, 1, 0, -2, 4, 2, 6, 9};
    int count = 0;
    for (int i {0}; i < sizeMatrix; ++i) {
        for (int j {0}; j < sizeMatrix; ++j) {
            matrix[i][j] = randomMatrix[count];
            ++count;
        }
    }
    for (int i {0}; i < sizeMatrix; ++i) {
        std::cout << '\n';
        for (int j {0}; j < sizeMatrix; ++j) {
            std::cout << matrix[i][j] << " ";
        }
    }
    std::cout << '\n';

    std::cout << "Determinant = " << Matrix::Determinant(matrix, matrix.size()) << std::endl;
//3.
    std::vector<int> some {1, 2, 3, 4, 5, 6};
    for (const int& i : Iterator(some)) {
        std::cout << i << " ";
    }
    std::cout << '\n';



    return 0;
}
