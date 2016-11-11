#ifndef ERROR_RMATRIX_H
#define ERROR_RMATRIX_H

#include "error_rmatrix_base.h"

namespace errRMatrix {

class errorDivisionZero : public errorRMatrixBase
{
public:
    const char* what()
    {
        return "errorRMatrix::attampt to divideby zero";
    }
};


class errorAddition : public errorRMatrixBase
{
public:
    const char* what()
    {
        return "errorRMatrix::matrix sizes are not equal";
    }
};

class errorMultiplation : public errorRMatrixBase
{
public:
    const char* what()
    {
        return "errorRMatrix::the matrix size does not correspond to the multiplation";
    }
};

}

#endif // ERROR_RMATRIX_H
