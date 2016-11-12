#ifndef ERROR_MARRAY_H
#define ERROR_MARRAY_H

#include "error_marray_base.h"

namespace errMarray {

class errorIndex : public errorMarrayBase
{
public:
    const char* what()
    {
        return "errorMarray::input incorrect index";
    }
};

}

#endif // ERROR_MARRAY_H
