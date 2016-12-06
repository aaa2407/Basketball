#ifndef PLANE_H
#define PLANE_H

#include"base_plane.h"
#include "point\point.h"
#include "geom_operations\operations.h"

class plane : public BasePlane
{
public:
    plane(double a = 0, double b = 0, double c = 0, double d = 0);
    plane(const point& normal, double d = 0);
    plane(const point& _normal, const point& _point);
    plane(const point& p1, const point& p2, const point& p3);
    plane(const plane& plane);

    virtual void set(double a, double b, double c, double d = 0);
    virtual void set(const point& normal, double d = 0);
    virtual void set(const point& _normal, const point& p1);
    virtual void set(const point& p1, const point& p2, const point& p3);
    void set(const plane& _plane);

    void setA(double a);
    void setB(double b);
    void setC(double c);
    void setD(double d);

    double a() const;
    double b() const;
    double c() const;
    double d() const;

    void negation();
    plane operator-() const;

    bool isCorrect() const;
    bool isIncorrect() const;
    bool operator!() const;

    double value(const point& copy) const;
    double value(double x, double y, double z) const;

    bool isInPlane(const point& copy, double error = 1e-5) const;
    bool isInPlane(double x, double y, double z, double error = 1e-5) const;

    point reflaction(const point& first) const;
    point project(const point& first) const;

    point norm() const;

    void normilize();

    array<double> toArray() const;
};


#endif // PLANE_H
