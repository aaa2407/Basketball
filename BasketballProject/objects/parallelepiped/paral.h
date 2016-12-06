#ifndef PARAL_H
#define PARAL_H

#include "objects\object_base\object.h"
#include "geom_operations\operations.h"
#define PARAL_CEILING 5
#define PARAL_FLOOR 4

class paral : public object
{
public:
    paral(const char* name = NULL, double width = 100, double lenght = 100, double height = 100,
          const point& cente = point(0, 0, 0), QColor color = QColor(Qt::black));
    paral(const char* name, const point& p1, const point p2, QColor color = QColor(Qt::black));
    paral(const paral& par);

    marray<polygon> createParallelObject(double radius) const;

    double minX() const;
    double minY() const;
    double minZ() const;
    double maxX() const;
    double maxY() const;
    double maxZ() const;

protected:
    void setLines();

private:
    void setPolygons();
};

#endif // PARAL_H
