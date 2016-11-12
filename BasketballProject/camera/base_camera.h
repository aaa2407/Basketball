#ifndef BASE_CAMERA_H
#define BASE_CAMERA_H

#include "point\point.h"
#include "real_matrix\real_matrix.h"

class BaseCamera
{
public:
    virtual bool upIncline(double) = 0;
    virtual bool downIncline(double) = 0;
    virtual void rotate(double) = 0;
    virtual void increase(double) = 0;
    virtual void decrease(double) = 0;

    virtual void up(double) = 0;
    virtual void down(double) = 0;
    virtual void left(double) = 0;
    virtual void right(double) = 0;
    virtual void forward(double) = 0;
    virtual void back(double) = 0;

    virtual double incline() const = 0;
    virtual double rotate() const = 0;
    virtual double distance() const = 0;

};


#endif // BASE_CAMERA_H
