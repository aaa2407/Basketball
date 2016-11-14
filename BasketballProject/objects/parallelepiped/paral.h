#ifndef PARAL_H
#define PARAL_H

#include "objects\object_base\object_base.h"

class paral : public object_base
{
public:
    paral(size_t width = 100, size_t lenght = 100, size_t height = 100, const point& cente = point(0, 0, 0));
    paral(const point& p1, const point p2);
    paral(const paral& par);

private:
    void setPolygons();
};

#endif // PARAL_H
