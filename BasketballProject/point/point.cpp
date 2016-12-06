#include "point.h"

point::point()
{
    this->_x = 0;
    this->_y = 0;
    this->_z = 0;
}

point::point(double x, double y, double z)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

point::point(const point& copy)
{
    this->_x = copy._x;
    this->_y = copy._y;
    this->_z = copy._z;
}

point::point(const array<double>& arr)
{
    if (arr.size() == 0)
    {
        _x = 0;
        _y = 0;
        _z = 0;
    }
    else if (arr.size() == 1)
    {
        _x = arr[0];
        _y = 0;
        _z = 0;
    }
    else if (arr.size() == 2)
    {
        _x = arr[0];
        _y = arr[1];
        _z = 0;
    }
    else
    {
        _x = arr[0];
        _y = arr[1];
        _z = arr[2];
    }
}

void point::set(double x, double y, double z)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

void point::set(const point& copy)
{
    this->_x = copy._x;
    this->_y = copy._y;
    this->_z = copy._z;
}

point& point::operator=(const point& copy)
{
    set(copy);
    return *this;
}

double point::x() const
{
    return this->_x;
}

double point::y() const
{
    return this->_y;
}

double point::z() const
{
    return this->_z;
}

void point::set_x(double x)
{
    this->_x = x;
}

void point::set_y(double y)
{
    this->_y = y;
}

void point::set_z(double z)
{
    this->_z = z;
}

void point::addition(const point& copy)
{
    this->_x += copy._x;
    this->_y += copy._y;
    this->_z += copy._z;
}

point point::operator+(const point& copy) const
{
    point newp(*this);
    newp._x += copy._x;
    newp._y += copy._y;
    newp._z += copy._z;
    return newp;
}


point& point::operator+=(const point& copy)
{
    this->_x += copy._x;
    this->_y += copy._y;
    this->_z += copy._z;
    return *this;
}


void point::subtraction(const point& copy)
{
    addition(-copy);
}

point point::operator-(const point& copy) const
{
    point newp(*this);
    newp.addition(-copy);
    return newp;
}

point& point::operator-=(const point& copy)
{
    addition(-copy);
    return *this;
}

void point::negation()
{
    this->_x = -this->_x;
    this->_y = -this->_y;
    this->_z = -this->_z;
}

point point::operator-() const
{
    point newp(*this);
    newp.negation();
    return newp;
}

double point::length() const
{
    return sqrt(_x*_x + _y*_y + _z*_z);
}

void point::normalization()
{
    if (this->length() == 0)
        return;
    this->set(_x/length(), _y/length(), _z/length());
}

bool point::zero() const
{
    return (!_x && !_y && !_z);
}

bool point::operator!()
{
    return zero();
}

array<double> point::toArray() const
{
    array<double> arr(4);
    arr[0] = _x;
    arr[1] = _y;
    arr[2] = _z;
    arr[3] = 1;
    return arr;
}

void point::transform(const transform_base& matr)
{
    array<double> arr = this->toArray();
    arr = arr * matr;
    _x = arr[0]/arr[3];
    _y = arr[1]/arr[3];
    _z = arr[2]/arr[3];
}

bool point::equal(const point& right) const
{
    if (_x == right._x && _y == right._y && _z == right._z)
        return true;
    else
        return false;
}

bool point::equal_not(const point& right) const
{
    if (_x == right._x && _y == right._y && _z == right._z)
        return false;
    else
        return true;
}

bool point::operator==(const point& right) const
{
    return this->equal(right);
}

bool point::operator!=(const point& right) const
{
    return equal_not(right);
}


point point::XoY() const
{
    return point(_x, _y, 0);
}

point point::XoZ() const
{
    return point(_x, 0, _z);
}

point point::YoZ() const
{
    return point(0, _y, _z);
}

point point::to2D() const
{
    point newp;
    newp.set_x(-this->y()*500/(-this->x() + 500));
    newp.set_y(this->z()*500/(-this->x() + 500));
    return newp;
}

void point::draw(Z_buffer_base *buf, const camera_base *cam) const
{
    point a = this->project(buf, cam);
    buf->setPixel(a.x(), a.y(), QColor(Qt::black), cam->distance(_x, _y, _z));
}

point point::camera(const camera_base* cam) const{
    return point(this->toArray()*cam->get());
}

point point::camera_for_normal(const camera_base* cam) const{
    return point(this->toArray()*cam->getVector());
}

point point::project(Z_buffer_base *buf, const camera_base *cam) const{
    point a(this->toArray()*cam->get());
    a = a.to2D();
    a.set_x(a.x() + buf->width()/2);
    a.set_y(-a.y() + buf->height()/2);
    return a;
}

void point::incZ(double k){
    _z += k;
}

void point::decZ(double k){
    _z -= k;
}

void point::incY(double k){
    _y += k;
}

void point::decY(double k){
    _y -= k;
}

void point::incX(double k){
    _x += k;
}

void point::decX(double k){
    _x -= k;
}

float length(const point& start, const point& end)
{
    point newp = end - start;
    return newp.length();
}

std::ostream& operator<<(std::ostream& cout, const point& copy)
{
    cout << "point(";
    double x = (fabs(copy.x()) > 1e-6) ? copy.x() : 0;
    double y = (fabs(copy.y()) > 1e-6) ? copy.y() : 0;
    double z = (fabs(copy.z()) > 1e-6) ? copy.z() : 0;
    cout << x << ", " << y << ", " << z << ")";
    return cout;
}
