#ifndef DIFFICULTMOMENTSCPP_MATRIX_H
#define DIFFICULTMOMENTSCPP_MATRIX_H

#include <iostream>
#include <vector>
#include <memory>


class Matrix {
public:
    //Constr, Destruct, Copy and Move constructor;
    Matrix(unsigned _rows, unsigned _columns);
    ~Matrix();
    Matrix(const Matrix& rhs);


    //Getters and Setters
    [[nodiscard]] unsigned getRows() const;
    [[nodiscard]] unsigned getColumns() const;

    //Determinant
    static double Determinant(std::vector<std::vector<int>>& matrix, size_t n);

    //Overload methods
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
private:
    std::vector<int> m_Matrix;
    unsigned m_Rows;
    unsigned m_Columns;
};



#endif //DIFFICULTMOMENTSCPP_MATRIX_H
