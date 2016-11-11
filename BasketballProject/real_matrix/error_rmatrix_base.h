#ifndef ERROR_RMATRIX_BASE_H
#define ERROR_RMATRIX_BASE_H

#include "D:\Basketball\Algorithm Roberts\Roberts\error\error_base.h"

class errorRMatrixBase : public errorBase
{
public:
    virtual const char* what() = 0;
};

#endif // ERROR_RMATRIX_BASE_H
