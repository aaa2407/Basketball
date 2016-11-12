#ifndef ERROR_Z_BUFFER_BASE_H
#define ERROR_Z_BUFFER_BASE_H

#include "error\error_base.h"

class error_Z_buffer_Base : public errorBase
{
public:
    virtual const char* what() = 0;
};

#endif // ERROR_Z_buffer_BASE_H
