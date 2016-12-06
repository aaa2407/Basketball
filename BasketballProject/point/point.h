#ifndef POINT_H
#define POINT_H

#include "math.h"
#include "drawing/drawing_object.h"
#include "drawing/z-buffer_base/z_buffer_base.h"

class point : public drawing_object
{
public:
    point();    
    point(double x, double y, double z = 0);
    point(const point &copy);
    point(const array<double>& arr);

    void set(double x, double y, double z = 0);
    void set(const point& copy);

    point& operator=(const point& copy);

    double x() const;
    double y() const;
    double z() const;

    void set_x(double x);
    void set_y(double y);
    void set_z(double z);

    void addition(const point& copy);
    point operator+(const point& copy) const;
    point& operator+=(const point& copy);
    
    void subtraction(const point &copy);
    point operator-(const point& copy) const;
    point& operator-=(const point& copy);

    void negation();
    point operator-() const;


    double length() const;
    static float length(const point& start, const point& end);

    void normalization();

    bool zero() const;
    bool operator!();

    void transform(const transform_base& matr);

    bool equal(const point& right) const;
    bool equal_not(const point& right) const;

    bool operator==(const point& right) const;
    bool operator!=(const point& right) const;

    array<double> toArray() const;
    point to2D() const;

    point XoY() const;
    point XoZ() const;
    point YoZ() const;

    void draw(Z_buffer_base *, const camera_base *) const;
    point camera(const camera_base*) const;
    point project(Z_buffer_base *, const camera_base *) const;
    point camera_for_normal(const camera_base* cam) const;

    void incZ(double);
    void decZ(double);
    void incY(double);
    void decY(double);
    void incX(double);
    void decX(double);

protected:
    double _x;
    double _y;
    double _z;
};

float length(const point& start, const point& end);
std::ostream& operator<<(std::ostream& cout, const point& copy);

#endif // POINT_H
