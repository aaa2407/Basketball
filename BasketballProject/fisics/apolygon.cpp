#include "apolygon.h"

apolygon::apolygon()
{
    _koef = 1;
}

double apolygon::koef() const
{
    return _koef;
}

void apolygon::set_koef(double koef)
{
    _koef = koef;
}

double apolygon::time_to(const traject& copy) const
{
    if (!operations::isConvexPolygon(*this))
    {
        return -1;
    }

    plane pl = this->get_plane();
    double A = -_G_/2 *pl.c();
    double B = pl.norm() * copy.napr;
    double C = pl.value(copy.pos)/_M_;
    double t;
    if (A != 0)
    {
        double D = B*B - 4*A*C;
        if (D < 0)
            return -1;
        t = (-B-sqrt(D))/2/A;
        double t2 = (-B+sqrt(D))/2/A;
        if (t2 < 0)
            return -1;
        if (t < 0)
            t = t2;
    }
    else
    {
        t = -C/B;
        if (t < 0)
            return -1;
    }
    point pt = point_at_time(copy, t*1000);
    std::cout << "\t" << pt;
    if (!operations::isInConvexPolygon(pt, *this, 1))
        return -1;
    else
        return t;
}
