#ifndef ERROR_TRAJECT_BASE_H
#define ERROR_TRAJECT_BASE_H

#include "D:\Basketball\Algorithm Roberts\Roberts\error\error_base.h"

class errorTrajectBase : public errorBase
{
public:
    virtual const char* what() = 0;
};

#endif // ERROR_TRAJECT_BASE_H
