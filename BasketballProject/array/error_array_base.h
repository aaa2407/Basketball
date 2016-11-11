#ifndef ERROR_ARRAY_BASE_H
#define ERROR_ARRAY_BASE_H

#include "error\error_base.h"

class errorArrayBase : public errorBase
{
public:
    virtual const char* what() = 0;
};

#endif // BASE_ERROR_VECTOR_H
