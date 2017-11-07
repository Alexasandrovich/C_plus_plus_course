//
// Created by Александр on 07.11.2017.
//
#include "matrixU.h"
#include <iostream>

MatrixU::MatrixU():pData_{nullptr} {} // +

MatrixU::MatrixU(const MatrixU &matrix): // +
        nRow_{matrix.nRow_}, nCol_{matrix.nCol_}, pData_(new int[nCol_*nRow_])
{
    pData_ = matrix.pData_;
}


MatrixU MatrixU::operator=(const MatrixU &rhs) // +
{
    nRow_=rhs.nRow_;
    nCol_=rhs.nRow_;
    pData_= new int[nRow_*nCol_];
    pData_ = rhs.pData_;
    return *this;
}

int& MatrixU::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
    if (iRow < 0 || iCol<0 || iRow >= nRow_ || iCol >= nCol_)
    {
        throw ("Your index is outside the matrix boundaries. Fix it");
    }
    return pData_[iCol*iRow + iCol];
}

const int& MatrixU::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
    if (iRow < 0 || iCol<0 || iRow >= nRow_ || iCol >= nCol_)
    {
        throw ("Your index is outside the matrix boundaries. Fix it");
    }
    return pData_[iCol*iRow + iCol];
}
std::ostream& MatrixU ::writeTo(std::ostream &ostrm) const
{
    for (int i(0); i < nRow_; i++){
        for (int j(0); j < nCol_; j++) {
            ostrm  <<  " " <<pData_[nCol_*i+j] << " ";
        }
        ostrm << std::endl;
    }
    return ostrm;
}
std::ostream& operator<<(std::ostream& ostrm, const MatrixU& matrix)
{
    return matrix.writeTo(ostrm);
}
MatrixU::~MatrixU()
{
    delete[] pData_;
    nRow_ = 0;
    nCol_ = 0;
    pData_ = {nullptr};

}

