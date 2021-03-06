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
    double scalar = p1.x()*p2.x() + p1.y()*p2.y() + p1.z()*p2.z();
    if (fabs(scalar) < 1e-5)
        scalar = 0;
    return scalar;
}



double operator*(const point& p1, const point& p2)
{
    return operations::scalar_multi(p1, p2);
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
    //std::cout << "ref " << p << " --> ";
    double len = p.length();
    p.normalization();
    double cosn = (n.x()*p.x() + n.y()*p.y() + n.z()*p.z());
    cosn /= n.x()*n.x() + n.y()*n.y() + n.z()*n.z();
    point r;
    r.set_x((2*n.x()*cosn - p.x())*len);
    r.set_y((2*n.y()*cosn - p.y())*len);
    r.set_z((2*n.z()*cosn - p.z())*len);
    //std::cout << r << std::endl;
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


point operations::intersection2D(const point& L11, const point& L12,
                               const point& L21, const point& L22)
{
    marray<point> arr;
    arr.add(L11);
    arr.add(L12);
    arr.add(L21);
    arr.add(L22);
    double z = arr[0].z();
    for (size_t i = 1; i < arr.size(); i++)
    {
        if (z != arr[i].z())
            return point(0, 0, -1.23);
    }
    point p1 = L12 - L11;
    point p2 = L22 - L21;
    p1.normalization();
    p2.normalization();
    if (p1 == p2 || p1 == -p2)
    {
        return point(0, 0, -1.23);
    }
    p1 = p1^point(0, 0, 1);
    p2 = p2^point(0, 0, 1);
    double a1, b1, c1;
    double a2, b2, c2;
    a1 = p1.x();
    b1 = p1.y();
    a2 = p2.x();
    b2 = p2.y();
    c1 = - a1*L11.x() - b1*L11.y();
    c2 = - a2*L21.x() - b2*L21.y();
    double det, det_1, det_2;
    det = a1*b2 - a2*b1;
    det_1 = c1*b2 - c2*b1;
    det_2 = a1*c2 - a2*c1;
    return point(det_1/det, det_2/det, z);
}



color::rgb operations::Lambert(color::rgb col, const point& p, const point& n, const point& s){
    point _s = s - p;
    _s.normalization();
    point _n = n;
    _n.normalization();
    double c = fabs(_n*_s);
    if (c < 0)
        c = 0;
    col.red  = col.red  + (255 - col.red)*c*0.7;
    col.green = col.green + (255 - col.green)*c*0.7;
    col.blue = col.blue + (255 - col.blue)*c*0.7;
    return col;
}


color::rgb operations::Fong(color::rgb col, const point& p, const point& n,
                            const point& s, const point& cam){

    point _n = n;
    _n.normalization();
    point _c = cam - p;
    _c.normalization();
    point _s = s - p;
    _s.normalization();
    point _h = _c + _s;
    _h.normalization();
    double fong = pow(_n*_h, 10);
    if (fong < 0)
        fong = 0;
    double lamb = (_s*_n + 1);
    if (lamb < 0)
        lamb = 0;
    lamb /= 2;
    color::rgb c1;
    c1.red   = col.red * fong;
    c1.green = col.green * fong;
    c1.blue  = col.blue * fong;
    color::rgb c2;
    c2.red   = col.red * lamb;
    c2.green = col.green * lamb;
    c2.blue  = col.blue * lamb;
    color::rgb c3;
    c3.red   = col.red * 0.7;
    c3.green = col.green * 0.7;
    c3.blue  = col.blue * 0.7;
    int r, g, b;
    r = (int)c1.red + (int)c2.red + (int)c3.red;
    g = (int)c1.green + (int)c2.green + (int)c3.green;
    b = (int)c1.blue + (int)c2.blue + (int)c3.blue;
    //r = (int)c2.red + (int)c3.red;
    //g = (int)c2.green + (int)c3.green;
    //b = (int)c2.blue + (int)c3.blue;
    r = (r > 255) ? 255 : r;
    g = (g > 255) ? 255 : g;
    b = (b > 255) ? 255 : b;
    col.red = r;
    col.green = g;
    col.blue = b;
    return col;
}
