#include <random>

#include "Matrix.h"

Matrix::Matrix(const unsigned int _rows, const unsigned int _columns) : m_Rows(_rows), m_Columns(_columns) {
    if (_rows != _columns) {
        throw std::runtime_error("Matrix is not square!!!");
    }
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(-20, 20);

    m_Matrix.resize(_rows * _columns);
    for (int i = 0; i < m_Rows; ++i) {
        for (int j = 0; j < m_Columns; ++j) {
            m_Matrix[i * m_Rows + j] = dist(rd);
        }
    }
    std::cout << "Matrix()" << std::endl;
}

Matrix::Matrix(const Matrix &rhs) {
    m_Matrix = rhs.m_Matrix;
    m_Columns = rhs.getColumns();
    m_Rows = rhs.getRows();
}

std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    for (int i = 0; i < m.m_Rows; ++i) {
        std::cout << '\n';
        for (int j = 0; j < m.m_Columns; ++j) {
            os << m.m_Matrix.at(i * m.m_Columns + j) << " ";
        }
    }

    std::cout << std::endl;

    return os;
}

Matrix::~Matrix() {
    std::cout << "~Matrix()" << std::endl;
}

unsigned Matrix::getRows() const {
    return m_Rows;
}

unsigned Matrix::getColumns() const {
    return m_Columns;
}

double Matrix::Determinant(std::vector<std::vector<int>>& matrix, size_t n) {
    if (n == 2) {
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    }
    else if (n == 1) {
        return matrix[0][0];
    }
    else {
        std::vector<std::vector<int>> subMatrix(n - 1);
        for (int i {0}; i < n - 1; ++i) {
            subMatrix[i].resize(n - 1);
        }
        double det = 0;
        int a{};
        int b{};
        for (int i = {0}; i < n; ++i) {
            a = 0;
            for (int j = 1; j < n; ++j) {
                b = 0;
                for (int k {0}; k < n; ++k) {
                    if (k != i) {
                        subMatrix[a][b] = matrix[j][k];
                        ++b;
                    }
                }
                ++a;
            }
            det += pow(-1, (double) i + 2) * matrix[0][i] * Determinant(subMatrix, n - 1);
        }
        return det;
    }

}

































