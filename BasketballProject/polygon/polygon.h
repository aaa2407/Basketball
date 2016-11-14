#ifndef POLYGON_H
#define POLYGON_H

#include "mutable_array\marray.h"
#include "point\point.h"
#include "geom_operations\operations.h"
#include "error_polygon.h"

class polygon : public marray<point>
{
public:
    polygon();

    void changeNormal();
    point normal() const;
    plane get_plane() const;

public:
    bool napr;
};

#endif // POLYGON_H
