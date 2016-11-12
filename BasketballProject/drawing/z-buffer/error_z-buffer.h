#ifndef ERROR_Z_BUFFER_H
#define ERROR_Z_BUFFER_H

#include "error_z-buffer_base.h"

namespace err_Z_buffer {

class errorPixel: public error_Z_buffer_Base
{
public:
    const char* what()
    {
        return "error_Z_buffer::you are chosen the incorrect pixel";
    }
};

class errorCamera: public error_Z_buffer_Base
{
public:
    const char* what()
    {
        return "error_Z_buffer::the camera is empty";
    }
};

}

#endif // ERROR_Z_buffer_H
