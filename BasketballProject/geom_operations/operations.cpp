#include "operations.h"

point operations::number_multi(const point& p, double k)
{
    return point(p.x()*k, p.y()*k, p.z()*k);
}

point operator*(const point& p, double k)
{
    return point(p.x()*k, p.y()*k, p.z()*k);
}

point operator*(double k, const point& p)
{
    return point(p.x()*k, p.y()*k, p.z()*k);
}

double operations::scalar_multi(const point& p1, const point& p2)
{
    return p1.x()*p2.x() + p1.y()*p2.y() + p1.z()*p2.z();
}



double operator*(const point& p1, const point& p2)
{
    return p1.x()*p2.x() + p1.y()*p2.y() + p1.z()*p2.z();
}


double operations::cos_fi(const point& p1, const point& p2)
{
    point a = p1, b = p2;
    a.normalization();
    b.normalization();
    return a * b;
}

point operations::vector_multi(const point& p1, const point& p2)
{
    point p;
    p.set_x(p1.y()*p2.z() - p1.z()*p2.y());
    p.set_y(p1.z()*p2.x() - p1.x()*p2.z());
    p.set_z(p1.x()*p2.y() - p1.y()*p2.x());
    return p;
}

point operator^(const point& p1, const point&p2)
{
    return operations::vector_multi(p1, p2);
}

point operations::normal(const point& p1, const point& p2, const point& p3)
{
     double x = (p2.y() - p1.y())*(p3.z() - p1.z()) - (p2.z() - p1.z())*(p3.y() - p1.y());
     double y = (p2.z() - p1.z())*(p3.x() - p1.x()) - (p2.x() - p1.x())*(p3.z() - p1.z());
     double z = (p2.x() - p1.x())*(p3.y() - p1.y()) - (p2.y() - p1.y())*(p3.x() - p1.x());
    point p = point(x, y, z);
    p.normalization();
    return p;
}

point operations::nspeed( double fi, double tau, double speed)
{
    point p;
    p.set_x(speed*cos(tau)*cos(fi));
    p.set_y(speed*cos(tau)*sin(fi));
    p.set_z(speed*sin(tau));
    return p;
}

point operations::reflation_napr(const point& falling, const point& normal)
{
    point n = normal;
    n.normalization();
    point p = falling;
    std::cout << "ref " << p << " --> ";
    double len = p.length();
    p.normalization();
    double cosn = (n.x()*p.x() + n.y()*p.y() + n.z()*p.z());
    cosn /= n.x()*n.x() + n.y()*n.y() + n.z()*n.z();
    point r;
    r.set_x((2*n.x()*cosn - p.x())*len);
    r.set_y((2*n.y()*cosn - p.y())*len);
    r.set_z((2*n.z()*cosn - p.z())*len);
    std::cout << r << std::endl;
    return -r;
}


bool operations::isPolygon(const marray<point>& arr, double error)
{
    if (arr.size() < 3)
    {
        return false;
    }
    else if (arr.size() == 3)
    {
        return true;
    }
    else
    {
        plane pl(arr[0], arr[1], arr[2]);
        bool ok = true;
        for (uint i = 3; i < arr.size(); i++)
        {
            ok = ok && pl.isInPlane(arr[i], error);
        }
        return ok;
    }
}

bool operations::isConvexPolygon(const marray<point>& arr, double error)
{
    if (arr.size() == 3)
    {
        return true;
    }
    if (!isPolygon(arr, error))
    {
        return false;
    }
    bool ok = true;
    uint c = arr.size();
    point k;
    for(uint i = 0; i < c; i++)
    {
        point p1 = arr[(i+1)%c] - arr[i];
        point p2 = arr[(i+2)%c] - arr[(i+1)%c];
        if (i == 0)
        {
            k = p1^p2;
        }
        else
        {
            if (k*(p1^p2) < 0)
                ok = false;
        }
    }
    return ok;
}

bool operations::isInConvexPolygon(const point& p, const marray<point>& arr, double error)
{
    if (!isConvexPolygon(arr, error))
    {
        return false;
    }
    plane pl(arr[0], arr[1], arr[2]);
    if (!pl.isInPlane(p, error))
    {
        return false;
    }
    bool ok = true;
    uint c = arr.size();
    point k;
    for(uint i = 0; i < c; i++)
    {
        point p1 = arr[(i+1)%c] - arr[i];
        point p2 = p - arr[i];
        if (i == 0)
        {
            k = p1^p2;
        }
        else
        {
            if (k*(p1^p2) < 0)
                ok = false;
        }
    }
    return ok;
}
