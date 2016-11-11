#ifndef TRASFORM_MATRIX_H
#define TRASFORM_MATRIX_H

#include "transform_matrix_base.h"
#include "math.h"

namespace TransformMatrix{

class moveX : public transform_base
{
public:
    moveX(double x)
    {
        (*this)[3][0] = x;
    }
};

class moveY : public transform_base
{
public:
    moveY(double y)
    {
        (*this)[3][1] = y;
    }
};


class moveZ : public transform_base
{
public:
    moveZ(double z)
    {
        (*this)[3][2] = z;
    }
};

class move : public transform_base
{
public:
    move(double x, double y, double z)
    {
        (*this)[3][0] = x;
        (*this)[3][1] = y;
        (*this)[3][2] = z;
    }
};

class rotateX : public transform_base
{
public:
    rotateX(double fi)
    {
        double cosfi = cos(fi);
        double sinfi = sin(fi);
        (*this)[1][1] = cosfi;
        (*this)[2][2] = cosfi;
        (*this)[1][2] = sinfi;
        (*this)[2][1] = -sinfi;
    }
};


class rotateY: public transform_base
{
public:
    rotateY(double fi)
    {
        double cosfi = cos(fi);
        double sinfi = sin(fi);
        (*this)[0][0] = cosfi;
        (*this)[2][2] = cosfi;
        (*this)[0][2] = -sinfi;
        (*this)[2][0] = sinfi;
    }
};

class rotateZ: public transform_base
{
public:
    rotateZ(double fi)
    {
        double cosfi = cos(fi);
        double sinfi = sin(fi);
        (*this)[0][0] = cosfi;
        (*this)[1][1] = cosfi;
        (*this)[0][1] = sinfi;
        (*this)[1][0] = -sinfi;
    }
};

class scale: public transform_base
{
public:
    scale(double koef)
    {
        if (!koef)
            koef = 1;
        (*this)[0][0] = koef;
        (*this)[1][1] = koef;
        (*this)[2][2] = koef;
    }
};

}

#endif // TRASFORM_MATRIX_H
