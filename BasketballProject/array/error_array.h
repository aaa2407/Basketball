#ifndef ERROR_ARRAY_H
#define ERROR_ARRAY_H

#include "error_array_base.h"

namespace errArray {

class errorMemory: public errorArrayBase
{
public:
    const char* what()
    {
        return "errorArray::memory is not allocated";
    }
};

class errorIndex : public errorArrayBase
{
public:
    const char* what()
    {
        return "errorArray::input incorrect index";
    }
};

}

#endif // ERROR_ARRAY_H
