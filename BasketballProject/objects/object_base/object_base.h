#ifndef OBJECT_BASE_H
#define OBJECT_BASE_H

#include "point\point.h"
#include "mutable_array\marray.h"
#include "polygon\polygon.h"

class object_base
{
public:
    object_base();

    polygon getPolygon(size_t index) const;
    size_t  getPolygonCount() const;

    const point& centre() const;
    void setOutwardNormal(bool ok);
    bool outwardNormal() const;

protected:
    bool setConnect();

protected:
    marray<point> _vertex;
    array<marray<size_t>> _connect;
    marray<marray<size_t>> _polygons;
    point _centre;
    bool _outward_normal;
};

#endif // OBJECT_BASE_H
