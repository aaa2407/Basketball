#ifndef ERROR_LINE2D_BASE_H
#define ERROR_LINE2D_BASE_H

#include "error\error_base.h"

class errorLine2DBase : public errorBase
{
public:
    virtual const char* what() = 0;
};

#endif // ERROR_LINE2D_BASE_H
