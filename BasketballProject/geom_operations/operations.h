#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "point\point.h"
#include "plane\plane.h"
point number_multi(const point&, double);
point operator*(const point&, double);
point operator*(double, const point&);

double scalar_multi(const point&, const point&);
double operator*(const point&, const point&);

double cos_fi(const point&, const point&);
double sin_fi(const point&, const point&);

point vector_multi(const point&, const point&);
point operator^(const point&, const point&);

point normal(const point& p1, const point& p2, const point& p3);

point nspeed(double fi, double tau, double speed);

point reflation_napr(const point& falling, const point& normal);

bool isPolygon(const array<point>&, double error = 1e-5);
bool isConvexPolygon(const array<point>&, double error = 1e-5);
bool isInConvexPolygon(const point&, const array<point>&, double error = 1e-5);



#endif // OPERATIONS_H
