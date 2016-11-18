#ifndef ERROR_LINE2D_H
#define ERROR_LINE2D_H

#include "error_line2d_base.h"

namespace errLine2D{

class errorIncorrectSet: public errorArrayBase
{
public:
    const char* what()
    {
        return "errorIncorrectSet::incorrect coordinates";
    }
};

}

#endif // ERROR_LINE2D_H
