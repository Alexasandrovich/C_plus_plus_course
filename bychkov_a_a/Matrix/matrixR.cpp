//
// Created by Александр on 07.11.2017.
//v

#include "matrixR.h"
#include <iostream>

MatrixR::MatrixR() : pRows_{ new int* [nRow_]} {} // so difficult  +

MatrixR::MatrixR(const ptrdiff_t nRow, const ptrdiff_t nCol) : nRow_{nRow}, nCol_{nCol}, pRows_{new int* [nRow]} // +
{
    if (nRow < 0 || nCol < 0)
    {
        throw("Your matrix has zero Rows or Columns. Fix it, please");
    }
    for (ptrdiff_t i(0); i<nRow; i++)
    {
        pRows_[i]=new int[nCol];
    }
}
void MatrixR::realization(const MatrixR& matrix) //+
{
    nRow_=matrix.nRow_;
    nCol_=matrix.nCol_;
    pRows_=new int*[nRow_];
    for (ptrdiff_t i(0);i<nRow_;i++)
    {
        for (ptrdiff_t j(0);j<nCol_;j++)
        {
            pRows_[i][j]=matrix.pRows_[i][j];
        }
    }
}
MatrixR MatrixR::operator=(const MatrixR &rhs)
{
    realization(rhs);
    return *this;
}

MatrixR::MatrixR(const MatrixR &matrix)
{
    realization(matrix);
}

int& MatrixR::at(const ptrdiff_t iRow, const ptrdiff_t iCol) // +
{
    if(iRow < 0 || iCol < 0 || iRow>=nRow_ || iCol>=iRow)
    {
        throw("Your index is outside the matrix boundaries. Fix it");
    }
    return pRows_[iRow][nRow_];
}

const int& MatrixR::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const // +
{
    if(iRow < 0 || iCol < 0 || iRow>=nRow_ || iCol>=iRow)
    {
        throw("Your index is outside the matrix boundaries. Fix it");
    }
    return pRows_[iRow][iCol];
}
MatrixR::~MatrixR() // +
{
    for (ptrdiff_t i(0); i<nRow_; i++)
    {
        delete[] pRows_[i];
    }
    nRow_ = 0;
    nCol_ = 0;
    pRows_ = {nullptr};
}
std::ostream& MatrixR::writeTo(std::ostream &ostrm) const // +
{
    for (int i(0); i < nRow_; i++){
        for (int j(0); j < nCol_; j++) {
            ostrm  << " "<< pRows_[i][j] << " ";
        }
        ostrm << std::endl;
    }
    return ostrm;
}
std::ostream& operator<<(std::ostream& ostrm, const MatrixR matrix) // +
{
    return matrix.writeTo(ostrm);
}