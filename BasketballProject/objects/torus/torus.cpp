#include "torus.h"

torus::torus(const char* name, double MainRadius, double TorusRadius, size_t c1, size_t c2
             , const point& p, QColor color){

    _name = (name != NULL) ? (char*)name : NULL;
    _main_radius = MainRadius;
    _torus_radius = TorusRadius;
    _centre = p;
    _color = get_rgb(color);
    _c1 = c1;
    _c2 = c2;
    for (double fi = -M_PI; fi < M_PI - M_PI/_c1; fi += M_PI/_c1*2) {
        point p(MainRadius*cos(fi), MainRadius*sin(fi), 0);
        _torus_centres.add(p);
        point pn = p;
        pn.normalization();
        pn.set_x(pn.x()*TorusRadius);
        pn.set_y(pn.y()*TorusRadius);
        for (double inc = -M_PI; inc < M_PI - M_PI/_c2; inc += M_PI/_c2*2)
        {
            point a = pn;
            a.set_x(a.x()*cos(inc));
            a.set_y(a.y()*cos(inc));
            a.set_z(TorusRadius*sin(inc));
            _vertex.add(point(p + a));
        }
    }
    setPolygons();
    setConnect();
    setNormalsOnVertex();
    initColors();
}

torus::torus(const torus &copy){
    _name = (copy._name != NULL) ? copy._name : NULL;
    _main_radius = copy._main_radius;
    _torus_radius = copy._torus_radius;
    _vertex = copy._vertex;
    _centre = copy.centre();
    _torus_centres = copy._torus_centres;
    setPolygons();
    setConnect();
    setNormalsOnVertex();
    initColors();
}


void torus::setPolygons()
{
    _polygons.clear();
    size_t i1, j1;
    for (size_t i = 0; i < _c1; i++){
        i1 = (i+1)%_c1;
        for (size_t j = 0; j < _c2; j++){
            j1 = (j+1)%_c2;
            marray<size_t> pol;
            pol.add(i*_c2 + j);
            pol.add(i*_c2 + j1);
            pol.add(i1*_c2 + j1);
            pol.add(i1*_c2 + j);
            _polygons.add(pol);
        }
    }
}


marray<polygon> torus::createParallelObject(double radius) const{
    marray<point> points;
    size_t c1 = _c1*2;
    size_t c2 = _c2*2;
    for (double fi = -M_PI - M_PI/c1; fi < M_PI; fi += M_PI/c1*2) {
        point p(_main_radius*cos(fi), _main_radius*sin(fi), 0);
        point pn = p;
        pn.normalization();
        pn.set_x(pn.x()*(_torus_radius + radius));
        pn.set_y(pn.y()*(_torus_radius + radius));
        for (double inc = -M_PI; inc < M_PI - M_PI/c2; inc += M_PI/c2*2)
        {
            point a = pn;
            a.set_x(a.x()*cos(inc));
            a.set_y(a.y()*cos(inc));
            a.set_z((_torus_radius + radius)*sin(inc));
            points.add(point(p + a + _centre));
        } 
    }
    marray<polygon> arr;
    size_t i1, j1;
    for (size_t i = 0; i < c1; i++){
        i1 = (i+1)%c1;
        for (size_t j = 0; j < c2; j++){
            j1 = (j+1)%c2;
            polygon pol;
            pol.add(points[i*c2 + j]);
            pol.add(points[i*c2 + j1]);
            pol.add(points[i1*c2 + j1]);
            pol.add(points[i1*c2 + j]);
            arr.add(pol);
        }
    }
    return arr;

}

polygon torus::createCirclePolygon() const{
    polygon pol;
    for (size_t i = 0; i < _torus_centres.size(); i++){
        pol.add(_torus_centres[i] + _centre);
    }
    return pol;
}
