#ifndef ERROR_BALL_H
#define ERROR_BALL_H

#include "error_ball_base.h"

namespace errBall {

class errorNullPtr: public errorBallBase
{
public:
    const char* what()
    {
        return "errorBall::the sphere is empty";
    }
};

}

#endif // ERROR_BALL_H
