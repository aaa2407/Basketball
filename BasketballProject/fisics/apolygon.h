#ifndef APOLYGON_H
#define APOLYGON_H

#include "traject.h"
#include "polygon\polygon.h"

class apolygon : public polygon
{
public:
    apolygon();

    void set_koef(double);
    double koef() const;

    double time_to(const traject& copy) const;

private:
    double _koef;
};


#endif // POLYGON_H
