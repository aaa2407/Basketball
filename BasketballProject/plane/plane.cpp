#include "plane.h"

plane::plane(double a, double b, double c, double d)
{
    _a = a;
    _b = b;
    _c = c;
    _d = d;
    this->normilize();
}

plane::plane(const point& normal, double d)
{
    _a = normal.x();
    _b = normal.y();
    _c = normal.z();
    _d = d;
    this->normilize();
}

plane::plane(const point& _normal, const point& _point)
{
    _a = _normal.x();
    _b = _normal.y();
    _c = _normal.z();
    _d = - _a*_point.x() - _b*_point.y() - _c*_point.z();
    this->normilize();
}


plane::plane(const point& p1, const point& p2, const point& p3)
{
    point n = operations::normal(p1, p2, p3);
    _a = n.x();
    _b = n.y();
    _c = n.z();
    _d = - _a*p1.x() - _b*p1.y() - _c*p1.z();
    this->normilize();
}

plane::plane(const plane&  p)
{
    _a = p._a;
    _b = p._b;
    _c = p._c;
    _d = p._d;
    this->normilize();
}

void plane::set(double a, double b, double c, double d)
{
    _a = a;
    _b = b;
    _c = c;
    _d = d;
    this->normilize();
}

void plane::set(const point& normal, double d)
{
    _a = normal.x();
    _b = normal.y();
    _c = normal.z();
    _d = d;
    this->normilize();
}

void plane::set(const point& _normal, const point& p1)
{
    _a = _normal.x();
    _b = _normal.y();
    _c = _normal.z();
    _d = - _a*p1.x() - _b*p1.y() - _c*p1.z();
    this->normilize();
}

void plane::set(const point& p1, const point& p2, const point& p3)
{
    point vec1 = p2 - p1;
    point vec2 = p3 - p1;
    _a = (vec1.y()*vec2.z() - vec2.y()*vec1.z());
    _b = (vec1.x()*vec2.y() - vec2.x()*vec1.z());
    _c = (vec1.x()*vec2.y() - vec2.x()*vec1.y());
    _d = - _a*p1.x() - _b*p1.y() - _c*p1.z();
    this->normilize();
}

void plane::set(const plane& _plane)
{
    _a = _plane._a;
    _b = _plane._b;
    _c = _plane._c;
    _d = _plane._d;
}

void plane::setA(double a)
{
    _a = a;
}

void plane::setB(double b)
{
    _b = b;
}

void plane::setC(double c)
{
    _c = c;
}

void plane::setD(double d)
{
    _d = d;
}

double plane::a() const
{
    return _a;
}

double plane::b() const
{
    return _b;
}

double plane::c() const
{
    return _c;
}

double plane::d() const
{
    return _d;
}

void plane::negation()
{
    _a = - _a;
    _b = - _b;
    _c = - _c;
    _d = - _d;
}

plane plane::operator-() const
{
    plane p(*this);
    p.negation();
    return p;
}

bool plane::isCorrect() const
{
    if (_a || _b || _c || _d)
        return true;
    else
        return false;
}

bool plane::isIncorrect() const
{
    if (!_a && !_b && !_c && !_d)
        return true;
    else
        return false;
}

bool plane::operator!() const
{
    return isIncorrect();
}

double plane::value(const point& copy) const
{
    return _a*copy.x() + _b*copy.y() + _c*copy.z() + _d;
}

double plane::value(double x, double y, double z) const
{
    return _a*x + _b*y + _c*z + _d;
}

bool plane::isInPlane(const point& copy, double error) const
{
    return (fabs(value(copy)) < fabs(error));
}

bool plane::isInPlane(double x, double y, double z, double error) const
{
    return (fabs(value(x, y, z)) < fabs(error));
}

point plane::reflaction(const point& first) const{
    return first + this->norm()*this->value(first)*(-2);
}

point plane::project(const point& first) const{
    return first - this->norm()*this->value(first);
}

point plane::norm() const
{
    return point(_a, _b, _c);
}

void plane::normilize()
{
    double n = this->norm().length();
    _a /= n;
    _b /= n;
    _c /= n;
    _d /= n;
}

array<double> plane::toArray() const
{
    array<double> arr;
    arr.setSize(4);
    arr[0] = _a;
    arr[1] = _b;
    arr[2] = _c;
    arr[3] = _d;
    for (uint i = 0; i < 4; i++)
        if (fabs(arr[i]) < 1e-6)
            arr[i] = 0;
    return arr;
}
