#ifndef ERROR_PLANE_BASE_H
#define ERROR_PLANE_BASE_H

#include "error/error_base.h"

class errorPlaneBase : public errorBase
{
public:
    virtual const char* what() = 0;
};

#endif // ERROR_PLANE_BASE_H
