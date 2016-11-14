#include "drawing_shading.h"


#include <QDebug>

drawingShading::drawingShading(size_t width, size_t height, size_t max_depth, QColor back)
    : drawing3Dbase(width, height, max_depth, back)
{ }

void drawingShading::draw(const object_base& obj)
{
    drawing3Dbase::draw(obj);
}

void drawingShading::draw(const polygon& pol)
{
    if (pol.size() == 0)
        return;
    if (pol.size() == 1)
    {
        drawing3Dbase::draw(pol[0]);
        return;
    }
    if (pol.size() == 2)
    {
        drawing3Dbase::draw(pol[0], pol[1]);
        return;
    }
    if (!operations::isConvexPolygon(pol))
    {
        return;
    }
    double ymin = this->height();
    double ymax = 0;
    for (size_t i = 0; i < pol.size(); i++)
    {
        point a = this->new_point(pol[i]);
        a = a.to2D();
        a.set_x(a.x() + this->width()/2);
        a.set_y(a.y() + this->height()/2);
        if (a.y() < ymin)
            ymin = a.y();
        if (a.y() > ymax)
            ymax = a.y();
    }
    qDebug() << QString::number(ymin) << " " << QString::number(ymax);
    size_t xmin[(size_t)ymax - (size_t)ymin + 1];
    size_t xmax[(size_t)ymax - (size_t)ymin + 1];
    double dmin[(size_t)ymax - (size_t)ymin + 1];
    double dmax[(size_t)ymax - (size_t)ymin + 1];
    for (size_t i = 0; i <= ymax - ymin; i++)

    {
        xmax[i] = 0;
        xmin[i] = this->width();
    }
    for (size_t i = 0; i < pol.size(); i++)
    {
        point b1 = pol[i];
        point a1 = this->new_point(b1);
        a1 = a1.to2D();
        a1.set_x(a1.x() + this->width()/2);
        a1.set_y(a1.y() + this->height()/2);
        point b2 = pol[(i+1)%pol.size()];
        point a2 = this->new_point(b2);
        a2 = a2.to2D();
        a2.set_x(a2.x() + this->width()/2);
        a2.set_y(a2.y() + this->height()/2);
        double _y0 = (a1.y() < a2.y()) ? a1.y() : a2.y();
        double _y1 = (a1.y() < a2.y()) ? a2.y() : a1.y();
        double _x0 = (a1.y() < a2.y()) ? a1.x() : a2.x();
        double _x1 = (a1.y() < a2.y()) ? a2.x() : a1.x();
        double _d0 = (a1.y() < a2.y()) ? this->distance(b1) : this->distance(b2);
        double _d1 = (a1.y() < a2.y()) ? this->distance(b2) : this->distance(b1);
        for (double y = _y0; y <= _y1; y += 1)
        {
            double x = _x0 + (_x1 - _x0)*((y - _y0)/(_y1 - _y0));
            double d = _d0 + (_d1 - _d0)*((y - _y0)/(_y1 - _y0));
            if (x < xmin[(size_t)y - (size_t)ymin])
            {
                xmin[(size_t)y - (size_t)ymin] = (size_t)x;
                dmin[(size_t)y - (size_t)ymin] = d;
            }
            if (x > xmax[(size_t)y - (size_t)ymin])
            {
                xmax[(size_t)y - (size_t)ymin] = (size_t)x;
                dmax[(size_t)y - (size_t)ymin] = d;
            }
        }
    }
    for (size_t y = 0; y <= ymax - ymin; y++)
    {
        if (xmax[y] < this->width())
        {
            double d = dmin[y];
            size_t count = xmax[y] - xmin[y];
            double dd;
            if (count != 0)
                dd = (dmax[y] - dmin[y])/count;
            else
                dd = 0;
            for (uint x = xmin[y]; x <= xmax[y]; x++)
            {
                setPixel(x, y+ymin, _color, (size_t) d);
                d += dd;
            }
        }
    }
}
