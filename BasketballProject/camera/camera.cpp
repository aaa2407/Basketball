#include "camera.h"

camera::camera()
{
    _centre.set(0, 0, 0);
    _position.set(500, 0, 0);
}

bool camera::upIncline(double koef)
{
    if (koef < 0)
        return false;
    float inc = this->incline();
    if (inc + koef > M_PI_2*11/12)
        return false;
    float rot = this->rotate();
    this->rotate(-rot);
    array<double> arr = (_position - _centre).toArray();
    _position = point(arr*TransformMatrix::rotateY(-koef)) + _centre;
    this->rotate(rot);
    return true;
}

bool camera::downIncline(double koef)
{
    if (koef < 0)
        return false;
    float inc = this->incline();
    if (inc - koef < -M_PI_2*11/12)
        return false;
    float rot = this->rotate();
    this->rotate(-rot);
    array<double> arr = (_position - _centre).toArray();
    _position = point(arr*TransformMatrix::rotateY(koef)) + _centre;
    this->rotate(rot);
    return true;
}

void camera::rotate(double angle)
{
    array<double> arr = (_position - _centre).toArray();
    _position = point(arr*TransformMatrix::rotateZ(angle)) + _centre;
}

void camera::increase(double koef)
{
    point p = _position - _centre;
    double k = p.length() - koef;
    if (k < 100)
        return;
    k /= p.length();
    p = p * k;
    _position = p + _centre;
}

void camera::decrease(double koef)
{
    this->increase(-koef);
}

void camera::up(double pos)
{
    _centre.set_z(_centre.z() + pos);
    _position.set_z(_position.z() + pos);
}

void camera::down(double pos)
{
    this->up(-pos);
}

void camera::left(double pos)
{
    _centre.set_y(_centre.y() - pos);
    _position.set_y(_position.y() - pos);
}

void camera::right(double pos)
{
    this->left(-pos);
}

void camera::forward(double pos)
{
    _centre.set_x(_centre.x() - pos);
    _position.set_x(_position.x() - pos);
}

void camera::back(double pos)
{
    this->forward(-pos);
}

double camera::incline() const
{
    point p = _position - _centre;
    if (p.length() == 0)
        return 0;
    return asin(p.z()/p.length());
}

double camera::rotate() const
{
    point p = (_position - _centre).XoY();
    if (!p)
        return 0;
    bool k = true;
    if (p.y() < 0)
        k = false;
    double _x = p.x();
    double _y = p.y();
    double alfa = acos(_x/sqrt(_x*_x + _y*_y));
    if (!k)
        alfa = M_PI*2 - alfa;
    return alfa;
}

double camera::distance() const
{
    return (_position - _centre).length();
}

transform_base camera::get() const
{
    transform_base matr;
    matr *= TransformMatrix::scale(500/this->distance());
    matr *= TransformMatrix::rotateY(this->incline());
    matr *= TransformMatrix::rotateZ(this->rotate());
    matr *= TransformMatrix::move(_centre.x(), _centre.y(), _centre.z());
    return matr;
}


const point& camera::centre() const
{
    return _centre;
}

const point &camera::position() const
{
    return _position;
}

point camera::vector() const
{
    point p = _centre - _position;
    p.normalization();
    return p;
}

point camera::new_point(const point& copy)
{
    return point(copy.toArray()*this->get());
}

point camera::new_vector(const point& copy)
{
    array<double> arr = copy.toArray();
    arr = arr * TransformMatrix::rotateY(this->incline());
    arr = arr * TransformMatrix::rotateZ(this->rotate());
    return point(arr);
}


int camera::distance(const point& copy)
{
    return (int)((_position - copy).length());
}
