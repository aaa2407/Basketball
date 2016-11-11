#ifndef BASE_PLANE_H
#define BASE_PLANE_H

#include "D:\Basketball\Algorithm Roberts\Roberts\types.h"

class BasePlane
{
public:
    virtual void setA(double a) = 0;
    virtual void setB(double b) = 0;
    virtual void setC(double c) = 0;
    virtual void setD(double d) = 0;
    virtual void set(double a, double b, double c, double d = 0) = 0;

    virtual double a() const = 0;
    virtual double b() const = 0;
    virtual double c() const = 0;
    virtual double d() const = 0;

    virtual void negation() = 0;

    virtual bool isCorrect()const= 0;
    virtual bool isIncorrect()const= 0;

protected:
    double _a, _b, _c, _d;
};

#endif // BASE_PLANE_H
