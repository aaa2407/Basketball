#include "sphere.h"

sphere::sphere(const char *name, double radius, size_t c1, size_t c2, const point &p)
{
    _name = (name != NULL) ? (char*)name : NULL;
    _c1 = c1;
    _c2 = c2;
    _vertex.add(point(0, 0, - radius));
    for (double inc = -M_PI_2 + M_PI/(c1+1); inc < M_PI_2; inc += M_PI/(c1+1))
        for (double fi = -M_PI; fi < M_PI - M_PI/c2; fi += M_PI/c2*2)
        {
            point p;
            p.set_x(radius*cos(inc)*cos(fi));
            p.set_y(radius*cos(inc)*sin(fi));
            p.set_z(radius*sin(inc));
            _vertex.add(p);
        }
    deleteRobert = true;
    _vertex.add(point(0, 0, radius));
    setPolygons();
    setConnect();
    initColors();
    setNormalsOnVertex();
    _centre = p;
}

sphere::sphere(const sphere& copy)
{
    _name = (copy._name != NULL) ? copy._name : NULL;
    _vertex = copy._vertex;
    setPolygons();
    setConnect();
    initColors();
    setNormalsOnVertex();
    _centre = copy.centre();
}


void sphere::setPolygons()
{
    _polygons.clear();
    for (size_t i = 0; i < _c2; i++){
        marray<size_t> pol;
        size_t j = (i+1)%_c2;
        pol.add(0); pol.add(i+1); pol.add(j+1);
        _polygons.add(pol);
        pol.clear();
    }
    for (size_t k = 0; k < _c1 - 1; k++)
        for (size_t i = 0; i < _c2; i++)
        {
            marray<size_t> pol;
            size_t j = (i+1)%_c2;
            pol.add(i+1+k*_c2);     pol.add(j+1+k*_c2);
            pol.add(j+1+(k+1)*_c2); pol.add(i+1+(k+1)*_c2);
            _polygons.add(pol);
            pol.clear();
        }
    for (size_t i = 0; i < _c2; i++){
        marray<size_t> pol;
        size_t j = (i+1)%_c2;
        pol.add(1+_c1*_c2); pol.add(i+1+(_c1-1)*_c2); pol.add(j+1+(_c1-1)*_c2);
        _polygons.add(pol);
        pol.clear();
    }
}


marray<polygon> sphere::createParallelObject(double radius) const{
    return marray<polygon>();
}

double sphere::radius() const{
    return _vertex[0].length();
}
