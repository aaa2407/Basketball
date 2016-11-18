#include "paral.h"

paral::paral(size_t width, size_t lenght, size_t height, const point &cen)
{
    _vertex.add(point(cen.x() - width/2, cen.y() - lenght/2, cen.z() - height/2)); // 0
    _vertex.add(point(cen.x() - width/2, cen.y() - lenght/2, cen.z() + height/2)); // 1
    _vertex.add(point(cen.x() - width/2, cen.y() + lenght/2, cen.z() - height/2)); // 2
    _vertex.add(point(cen.x() - width/2, cen.y() + lenght/2, cen.z() + height/2)); // 3
    _vertex.add(point(cen.x() + width/2, cen.y() - lenght/2, cen.z() - height/2)); // 4
    _vertex.add(point(cen.x() + width/2, cen.y() - lenght/2, cen.z() + height/2)); // 5
    _vertex.add(point(cen.x() + width/2, cen.y() + lenght/2, cen.z() - height/2)); // 6
    _vertex.add(point(cen.x() + width/2, cen.y() + lenght/2, cen.z() + height/2)); // 7
    setPolygons();
    setConnect();
    initColors();
    _centre = cen;
}

paral::paral(const point& p1, const point p2)
{
    double x1 = p1.x(), y1 = p1.y(), z1 = p1.z();
    double x2 = p2.x(), y2 = p2.y(), z2 = p2.z();
    _vertex.add(point(x1, y1, z1));
    _vertex.add(point(x1, y1, z2));
    _vertex.add(point(x1, y2, z1));
    _vertex.add(point(x1, y2, z2));
    _vertex.add(point(x2, y1, z1));
    _vertex.add(point(x2, y1, z2));
    _vertex.add(point(x2, y2, z1));
    _vertex.add(point(x2, y2, z2));
    setPolygons();
    setConnect();
    initColors();
    _centre = point((x1 + x2)/2, (y1 + y2)/2, (z1 + z2)/2);
}

paral::paral(const paral& par)
{
    _vertex = par._vertex;
    setPolygons();
    setConnect();
    initColors();
    _centre = par.centre();
}

void paral::setPolygons()
{
    marray<size_t> pol;
    pol.add(0); pol.add(1); pol.add(3); pol.add(2);
    _polygons.add(pol);
    pol.clear();
    pol.add(6); pol.add(7); pol.add(5); pol.add(4);
    _polygons.add(pol);
    pol.clear();
    pol.add(4); pol.add(5); pol.add(1); pol.add(0);
    _polygons.add(pol);
    pol.clear();
    pol.add(2); pol.add(3); pol.add(7); pol.add(6);
    _polygons.add(pol);
    pol.clear();
    pol.add(0); pol.add(2); pol.add(6); pol.add(4);
    _polygons.add(pol);
    pol.clear();
    pol.add(5); pol.add(7);  pol.add(3); pol.add(1);
    _polygons.add(pol);
}


void paral::initColors()
{
    _pol_text.setSize(_vertex.size());
    for (size_t i = 0; i < _pol_text.size(); i++)
    {
        _pol_text[i]._col.blue  = 0;
        _pol_text[i]._col.blue   = 0;
        _pol_text[i]._col.blue = 0;
        _pol_text[i]._pic = NULL;
        _pol_text[i]._pic_pos = 0;
    }
}
