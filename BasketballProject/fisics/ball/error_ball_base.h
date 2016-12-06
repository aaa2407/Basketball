#ifndef ERROR_BALL_BASE_H
#define ERROR_BALL_BASE_H

#include "error\error_base.h"

class errorBallBase : public errorBase
{
public:
    virtual const char* what() = 0;
};


#endif // ERROR_BALL_BASE_H
