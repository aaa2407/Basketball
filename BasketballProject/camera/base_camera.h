#ifndef BASE_CAMERA_H
#define BASE_CAMERA_H

#include "real_matrix\real_matrix.h"
#include "transform_matrix\transform_matrix_base.h"

class camera_base
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

    virtual double x() const = 0;
    virtual double y() const = 0;
    virtual double z() const = 0;

    virtual double xc() const = 0;
    virtual double yc() const = 0;
    virtual double zc() const = 0;

    virtual transform_base get() const = 0;
    virtual transform_base getVector() const = 0;
    virtual int distance(double x, double y, double z) const = 0;
};


#endif // BASE_CAMERA_H
