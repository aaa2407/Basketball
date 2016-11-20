#ifndef LINE2D_H
#define LINE2D_H

#include "point\point.h"
#include "error_line2d.h"
#include "geom_operations\operations.h"

class line2D
{
public:
    line2D(double a = 1, double b = 0, double c = 0);
    line2D(double x1, double y1, double x2, double y2);
    line2D(const line2D& copy);

    void set(double a, double b, double c);
    void set(double x1, double y1, double x2, double y2);
    void set(const line2D& copy);

    line2D& operator=(const line2D& copy);

    double a() const;
    double b() const;
    double c() const;

    bool equal(const line2D& right) const;
    bool operator==(const line2D& right) const;
    bool equalNot(const line2D& right) const;
    bool operator!=(const line2D& right) const;

    bool isParallel(const line2D& right) const;
    bool isPerpendicularly(const line2D& right) const;

    bool isInLine(double x, double y) const;

    point intersection(const line2D& right) const;
    point operator^(const line2D& right) const;

protected:
    double _a, _b, _c;
};

/*
std::ostream& operator<<(std::ostream& cout, const point& copy)
{
}*/

#endif // LINE2D_H
