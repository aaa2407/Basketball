#ifndef ERROR_MATRIX_H
#define ERROR_MATRIX_H

#include "error_matrix_base.h"

namespace errMatrix {

class errorIndex : public errorMatrixBase
{
public:
    const char* what()
    {
        return "errorMatrix::input incorrect index";
    }
};

class errorMemory: public errorMatrixBase
{
public:
    const char* what()
    {
        return "errorMatrix::memory is not allocated";
    }
};


class errorSetRow : public errorMatrixBase
{
public:
    const char* what()
    {
        return "errorMatrix::the array size and matrix count of columns are not equal";
    }
};

class errorSetColumn : public errorMatrixBase
{
public:
    const char* what()
    {
        return "errorMatrix::the array size and matrix count of rows are not equal";
    }
};

}

#endif // ERROR_MATRIX_H
