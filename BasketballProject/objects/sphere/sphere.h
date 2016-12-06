#ifndef SPHERE_H
#define SPHERE_H

#include "objects\object_base\object.h"

class sphere : public object
{
public:
    sphere(const char* name = NULL, double radius = 15, size_t c1 = 5, size_t c2 = 10, const point& p = point(0, 0, 0));
    sphere(const sphere& copy);

    virtual marray<polygon> createParallelObject(double radius) const;

    double radius() const;

protected:
    void setLines(){}

private:
    void setPolygons();
    
private:
    size_t _c1;
    size_t _c2;
};

#endif // SPHERE_H
