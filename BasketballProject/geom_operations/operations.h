#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "point\point.h"
#include "plane\plane.h"
#include "mutable_array\marray.h"
#include "warning_operations.h"

namespace operations{

point number_multi(const point&, double);

double scalar_multi(const point&, const point&);

double cos_fi(const point&, const point&);
double sin_fi(const point&, const point&);

point vector_multi(const point&, const point&);

point normal(const point& p1, const point& p2, const point& p3);

point nspeed(double fi, double tau, double speed);

point reflation_napr(const point& falling, const point& normal);

bool isPolygon(const marray<point>& arr, double error = 1e-5);
bool isConvexPolygon(const marray<point>& arr, double error = 1e-5);
bool isInConvexPolygon(const point&p, const marray<point>&, double error = 1e-5);


point intersection2D(const point& L11, const point& L12,
                     const point& L21, const point& L22);

color::rgb Lambert(color::rgb, const point& p, const point& n, const point& s);
color::rgb Fong(color::rgb, const point& p, const point& n,
                            const point& s, const point& cam);

}

point operator*(const point&, double);
point operator*(double, const point&);
double operator*(const point&, const point&);
point operator^(const point&, const point&);


#endif // OPERATIONS_H
