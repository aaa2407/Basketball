#ifndef ERROR_TRAJECT_H
#define ERROR_TRAJECT_H

#include "error_traject_base.h"

namespace errTraject {

class errorMaxHigh: public errorTrajectBase
{
public:
    const char* what()
    {
        return "errorTraject::the high value of traject is incorrect";
    }
};

}

#endif // ERROR_TRAJECT_H
