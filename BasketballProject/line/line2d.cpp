#include "line2d.h"

line2D::line2D(double a, double b, double c)
{
    _a = a;
    _b = b;
    _c = c;
}

line2D::line2D(double x1, double y1, double x2, double y2)
{
    if (x2 == x1 && y2 == y1)
    {
        throw errLine2D::errorIncorrectSet();
    }
    point a = point(x2 - x1, y2 - y1, 0)^point(0, 0, 1);
    _a = a.x();
    _b = a.y();
    _c = -_a*x1 - _b*y1;
}

line2D::line2D(const line2D& copy)
{
    _a = copy._a;
    _b = copy._b;
    _c = copy._c;
}

void line2D::set(double a, double b, double c)
{
    _a = a;
    _b = b;
    _c = c;
}

void line2D::set(double x1, double y1, double x2, double y2)
{
    if (x2 == x1 && y2 == y1)
    {
        throw errLine2D::errorIncorrectSet();
    }
    point a = point(x2 - x1, y2, y1)^point(0, 0, 1);
    _a = a.x();
    _b = a.y();
    _c = -_a*x1 - _b*y1;
}

void line2D::set(const line2D& copy)
{
    _a = copy._a;
    _b = copy._b;
    _c = copy._c;
}

line2D& line2D::operator=(const line2D& copy)
{
    this->set(copy);
    return (*this);
}

double line2D::a() const
{
    return _a;
}

double line2D::b() const
{
    return _b;
}

double line2D::c() const
{
    return _c;
}

bool line2D::equal(const line2D& right) const
{
    if (_a == right._a && _b == right._b && _c == right._c)
        return true;
    else
        return false;
}

bool line2D::operator==(const line2D& right) const
{
    return this->equal(right);
}

bool line2D::equalNot(const line2D& right) const
{
    return !this->equal(right);
}

bool line2D::operator!=(const line2D& right) const
{
    return this->equalNot(right);
}

bool line2D::isParallel(const line2D& right) const
{
    point p1(_a, _b, 0);
    p1.normalization();
    point p2(right._a, right._b, 0);
    p2.normalization();
    if (p1.x() == p2.x() && p1.y() == p2.y())
        return true;
    else
        return false;
}

bool line2D::isPerpendicularly(const line2D& right) const
{
    point p = point(_a, _b)^point(right._a, right._b);
    if (p.x() == 0 && p.y() == 0 && p.z() != 0)
        return true;
    else
        return false;
}

bool line2D::isInLine(double x, double y) const
{
    if (fabs(_a*x + _b*y + _c) < 1e-6)
        return true;
    else
        return false;
}

point line2D::intersection(const line2D& right) const
{
    double det, det_1, det_2;
    det = _a*right._b - _b*right._a;
    det_1 = this->_c * right._b - right._c * this->_b;
    det_2 = this->_a * right._c - right._a * this->_c;
    return point(-det_1/det, -det_2/det, 0);
}

point line2D::operator^(const line2D& right) const
{
    return this->intersection(right);
}
