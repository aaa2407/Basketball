#include "paral.h"

paral::paral(const char* name, double width, double lenght, double height, const point &cen, QColor color)
{
    _name = name ? (char*)name : NULL;
    _centre = cen;
    _vertex.add(point(-width/2, -lenght/2, -height/2)); // 0
    _vertex.add(point(-width/2, -lenght/2, +height/2)); // 1
    _vertex.add(point(-width/2, +lenght/2, -height/2)); // 2
    _vertex.add(point(-width/2, +lenght/2, +height/2)); // 3
    _vertex.add(point(+width/2, -lenght/2, -height/2)); // 4
    _vertex.add(point(+width/2, -lenght/2, +height/2)); // 5
    _vertex.add(point(+width/2, +lenght/2, -height/2)); // 6
    _vertex.add(point(+width/2, +lenght/2, +height/2)); // 7
    _color = get_rgb(color);
    setPolygons();
    setConnect();
    setLines();
    initColors();
    setNormalsOnVertex();
}

paral::paral(const char *name, const point& p1, const point p2, QColor color)
{
    _name = name ? (char*)name : NULL;
    double x1 = p1.x(), y1 = p1.y(), z1 = p1.z();
    double x2 = p2.x(), y2 = p2.y(), z2 = p2.z();
    _centre = point((x1 + x2)/2, (y1 + y2)/2, (z1 + z2)/2);
    x1 -= _centre.x();
    x2 -= _centre.x();
    y1 -= _centre.y();
    y2 -= _centre.y();
    z1 -= _centre.z();
    z2 -= _centre.z();
    _vertex.add(point(x1, y1, z1));
    _vertex.add(point(x1, y1, z2));
    _vertex.add(point(x1, y2, z1));
    _vertex.add(point(x1, y2, z2));
    _vertex.add(point(x2, y1, z1));
    _vertex.add(point(x2, y1, z2));
    _vertex.add(point(x2, y2, z1));
    _vertex.add(point(x2, y2, z2));
    _color = get_rgb(color);
    setPolygons();
    setConnect();
    setLines();
    initColors();
    setNormalsOnVertex();
}

paral::paral(const paral& par)
{
    _name = (par._name != NULL) ? par._name : NULL;
    _vertex = par._vertex;
    _color = this->_color;
    _centre = par.centre();
    setPolygons();
    setConnect();
    setLines();
    initColors();
    setNormalsOnVertex();
}

marray<polygon> paral::createParallelObject(double radius) const{
    marray<polygon> marr;
    for (size_t i = 0; i < this->getPolygonCount(); i++){
        polygon pol = this->getPolygon(i);
        point n = pol.normal();
        if (!outwardNormal())
            n = -n;
        point p = n*radius;
        for (size_t j = 0; j < pol.size(); j++){
            pol[j] = pol[j] + p;
        }
        marr.add(pol);
    }
    if (outwardNormal() == false)
        return marr;
    for (size_t i = 0; i < _lines.size(); i++) {
        point p1 = _vertex[_lines[i].p1] + _centre;
        point p2 = _vertex[_lines[i].p2] + _centre;
        polygon pol1 = this->getPolygon(_lines[i].pol1);
        polygon pol2 = this->getPolygon(_lines[i].pol2);
        point n1 = pol1.normal(), n2 = pol2.normal();
        point n = n1 + n2; n.normalization();
        n = n * radius;
        n1 = n1 * radius;
        n2 = n2 * radius;
        polygon py1, py2;
        py1.add(p1+n1);  py1.add(p1+n);  py1.add(p2+n);  py1.add(p2+n2);
        py2.add(p1+n2);  py2.add(p1+n);  py2.add(p2+n);  py2.add(p2+n2);
        marr.add(py1);
        marr.add(py2);
    }
    for (size_t i = 0; i < _connect.size(); i++){
        point p = _vertex[i] + _centre;
        polygon pol1 = this->getPolygon(_connect[i][0]);
        polygon pol2 = this->getPolygon(_connect[i][1]);
        polygon pol3 = this->getPolygon(_connect[i][2]);
        point n1 = pol1.normal(); point n2 = pol2.normal(); point n3 = pol3.normal();
        point n12 = n1 + n2; point n23 = n2 + n3; point n13 = n1 + n3;
        point n = n1 + n2 + n3;
        n12.normalization();
        n13.normalization();
        n23.normalization();
        n.normalization();
        n = n * radius;
        n12 = n12 * radius;
        n23 = n23 * radius;
        n13 = n13 * radius;
        n1 = n1 * radius;
        n2 = n2 * radius;
        n3 = n3 * radius;
        polygon pol;
        pol.add(p+n); pol.add(p+n12); pol.add(p+n1);  marr.add(pol);
        pol.clear();  pol.add(p+n); pol.add(p+n12); pol.add(p+n2);  marr.add(pol);
        pol.clear();  pol.add(p+n); pol.add(p+n23); pol.add(p+n2);  marr.add(pol);
        pol.clear();  pol.add(p+n); pol.add(p+n23); pol.add(p+n3);  marr.add(pol);
        pol.clear();  pol.add(p+n); pol.add(p+n13); pol.add(p+n1); marr.add(pol);
        pol.clear();  pol.add(p+n); pol.add(p+n13); pol.add(p+n3); marr.add(pol);
    }
    return marr;
}

void paral::setLines(){
    _lines.clear();
    sline line;
    line.p1 = 0; line.p2 = 1;  line.pol1 = 0; line.pol2 = 2;
    _lines.add(line);
    line.p1 = 1; line.p2 = 3;  line.pol1 = 0; line.pol2 = 5;
    _lines.add(line);
    line.p1 = 3; line.p2 = 2;  line.pol1 = 0; line.pol2 = 3;
    _lines.add(line);
    line.p1 = 2; line.p2 = 0;  line.pol1 = 0; line.pol2 = 4;
    _lines.add(line);
    line.p1 = 6; line.p2 = 7;  line.pol1 = 1; line.pol2 = 3;
    _lines.add(line);
    line.p1 = 7; line.p2 = 5;  line.pol1 = 1; line.pol2 = 5;
    _lines.add(line);
    line.p1 = 5; line.p2 = 4;  line.pol1 = 1; line.pol2 = 2;
    _lines.add(line);
    line.p1 = 4; line.p2 = 6;  line.pol1 = 1; line.pol2 = 4;
    _lines.add(line);
    line.p1 = 0; line.p2 = 4;  line.pol1 = 4; line.pol2 = 2;
    _lines.add(line);
    line.p1 = 1; line.p2 = 5;  line.pol1 = 5; line.pol2 = 2;
    _lines.add(line);
    line.p1 = 2; line.p2 = 6;  line.pol1 = 4; line.pol2 = 3;
    _lines.add(line);
    line.p1 = 3; line.p2 = 7;  line.pol1 = 5; line.pol2 = 3;
    _lines.add(line);
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

double paral::minX() const{
   double x = 3000;
   for (size_t i = 0; i < _vertex.size(); i++)
        if (x > _vertex[i].x())
       x = _vertex[i].x();
   return x;
}

double paral::minY() const{
    double y = 3000;
    for (size_t i = 0; i < _vertex.size(); i++)
         if (y > _vertex[i].y())
             y = _vertex[i].y();
    return y;
}

double paral::minZ() const{
    double z = 3000;
    for (size_t i = 0; i < _vertex.size(); i++)
         if (z > _vertex[i].z())
        z = _vertex[i].z();
    return z;
}

double paral::maxX() const{
    double x = -3000;
    for (size_t i = 0; i < _vertex.size(); i++)
         if (x > _vertex[i].x())
        x = _vertex[i].x();
    return x;
}

double paral::maxY() const{
    double y = -3000;
    for (size_t i = 0; i < _vertex.size(); i++)
         if (y < _vertex[i].y())
             y = _vertex[i].y();
    return y;
}

double paral::maxZ() const{
    double z = -3000;
    for (size_t i = 0; i < _vertex.size(); i++)
         if (z < _vertex[i].z())
        z = _vertex[i].z();
    return z;
}
