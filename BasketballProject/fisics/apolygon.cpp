#include "apolygon.h"

double time_to(const polygon& pol, const traject& copy)
{
    if (!operations::isConvexPolygon(pol))
    {
        return -1;
    }
    plane pl = pol.get_plane();
    double A = -_G_/2 *pl.c();
    double B = pl.norm() * copy.napr;
    double C = pl.value(copy.pos)/_M_;
    double t, t2;
    if (A != 0)
    {
        double D = B*B - 4*A*C;
        if (D < 0)
            return -1;
        t = (-B-sqrt(D))/2/A;
        t2 = (-B+sqrt(D))/2/A;
        if (t2 < 0)
            return -1;
        if (t < 0)
            t = t2;
        else{
            if (t > t2){
                double t1 = t;
                t = t2;
                t2 = t1;
            }
        }
    }
    else
    {
        t = -C/B;
        if (t < 0)
            return -1;
    }
    point pt = point_at_time(copy, t*1000);
    if (operations::isInConvexPolygon(pt, pol, 1))
        return t;
    if (A != 0){
        pt = point_at_time(copy, t2*1000);
        if (operations::isInConvexPolygon(pt, pol, 1))
            return t2;
    }
    return -1;
}
