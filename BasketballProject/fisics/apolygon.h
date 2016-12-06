#ifndef APOLYGON_H
#define APOLYGON_H

#include "traject.h"
#include "polygon\polygon.h"

typedef struct {
    polygon _pol;
    double _koef;
} apolygon;

typedef struct {
    polygon _pol;
    char* _message;
    double _time;
} mpolygon;

double time_to(const polygon& pol, const traject& copy);


#endif // POLYGON_H
