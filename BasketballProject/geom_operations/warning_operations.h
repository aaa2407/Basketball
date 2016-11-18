#ifndef WARNING_OPERATIONS_H
#define WARNING_OPERATIONS_H

#include "error\warning_base.h"

namespace warningOperations{

class warningNoIntersaction: public warningBase
{
public:
    const char* what()
    {
        return "warningOperations::the lines hasn`t intersaction";
    }
};

}

#endif // WARNING_OPERATIONS_H
