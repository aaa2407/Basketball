#ifndef TRAJECT_H
#define TRAJECT_H

#include "point/point.h"
#include <iostream>
#define _G_ 9.80655
#define _M_ 100
#include "error_traject.h"

typedef struct{
    point pos;
    point napr;
} traject;

point point_at_time(const traject& traj, size_t time);

traject set_traject(const point& p1, const point& p2, double max_z);


#endif // TRAJECT_H
