#ifndef PARAL_H
#define PARAL_H

#include "objects\object_base\object.h"

#define PARAL_CEILING 5
#define PARAL_FLOOR 4

class paral : public object
{
public:
    paral(const char* name = NULL, size_t width = 100, size_t lenght = 100, size_t height = 100,  const point& cente = point(0, 0, 0));
    paral(const char* name, const point& p1, const point p2);
    paral(const paral& par);

private:
    void initColors();
    void setPolygons();
};

#endif // PARAL_H
