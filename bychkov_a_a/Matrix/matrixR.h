//
// Created by Александр on 07.11.2017.
//

#ifndef CMAKE_MATRIXR_H
#define CMAKE_MATRIXR_H

#include <iosfwd>

class MatrixR
{
public:
    MatrixR();
    MatrixR(const ptrdiff_t nRow, const ptrdiff_t nCol);
    MatrixR(const MatrixR& matrix);
    MatrixR operator=(const MatrixR& rhs);
    int& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
    const int& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;
    void realization(const MatrixR& matrix);
    std::ostream& writeTo(std::ostream& ostrm ) const;
    ~MatrixR();

private:
    int** pRows_{nullptr}; // massif
    ptrdiff_t nRow_{0};
    ptrdiff_t nCol_{0};
};

std::ostream& operator<< (std::ostream& ostrm, const MatrixR matrix);
#endif //CMAKE_MATRIXR_H
