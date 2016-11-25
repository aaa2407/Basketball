#ifndef SPHERE_H
#define SPHERE_H

#include "objects\object_base\object.h"

class sphere : public object
{
public:
    sphere(const char* name = NULL, double radius = 15, size_t c1 = 5, size_t c2 = 10, const point& p = point(0, 0, 0));
    sphere(const sphere& copy);

    polygon getPolygon(size_t index) const;

    void transform(const transform_base& matr);

private:
    void initColors();
    void setPolygons();
    
private:
    size_t _c1;
    size_t _c2;
};

#endif // SPHERE_H
