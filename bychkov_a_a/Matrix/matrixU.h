//
// Created by Александр on 07.11.2017.
//

#ifndef CMAKE_MATRIXU_H
#define CMAKE_MATRIXU_H

#include <iosfwd>

class MatrixU
{
public:
    MatrixU();
    MatrixU(const MatrixU& matrix);
    MatrixU operator=(const MatrixU& rhs);
    /*MatrixU operator+=(const MatrixU rhs);
    MatrixU operator-=(const MatrixU rhs);
    MatrixU operator*=(const MatrixU rhs);*/
    int& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
    const int& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const ;
    std::ostream& writeTo(std::ostream& ostrm) const;
    ~MatrixU();

private:
    ptrdiff_t nRow_{0};
    ptrdiff_t nCol_{0};
    int* pData_{nullptr};
};

std::ostream& operator<<(std::ostream& ostrm, const MatrixU matrix);

#endif //CMAKE_MATRIXU_H
