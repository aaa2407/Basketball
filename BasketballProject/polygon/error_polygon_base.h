#ifndef ERROR_POLYGON_BASE_H
#define ERROR_POLYGON_BASE_H

#include "error\error_base.h"

class errorPolygonBase : public errorBase
{
public:
    virtual const char* what() = 0;
};

#endif // ERROR_POLYGON_BASE_H
