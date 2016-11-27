#ifndef TORUS_H
#define TORUS_H

#include "objects/object_base/object.h"

class torus : public object
{
public:
    torus(const char* name = NULL, double MainRadius = 25, double TorusRadius = 4, size_t c1 = 24, size_t c2 = 6,
          const point& p = point(0, 0, 0), QColor color = QColor(Qt::black));
    torus(const torus &copy);

    polygon getPolygon(size_t index) const;

    void transform(const transform_base& matr);

    virtual marray<polygon> createParallelObject(double radius) const;

protected:
    void setPolygons();
    void setLines(){}

private:
    double _main_radius, _torus_radius;
    marray<point> _torus_centres;
    size_t _c1;
    size_t _c2;
};

#endif // TORUS_H
