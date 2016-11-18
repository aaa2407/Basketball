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
    if (!operations::isConvexPolygon(pol) || pol.size() < 3)
    {
        return;
    }
    point p1, p2, p3, p4;
    double ymin = this->height();
    double ymax = 0;
    for (size_t i = 0; i < pol.size(); i++)
    {
        point a = this->new_point(pol[i]);
        if (pol.isTexture())
        {
            if (i == pol.getTexturePos())
                p1 = a;
            if (i == (pol.getTexturePos() + 1) % pol.size())
                p2 = a;
            if (pol.getTexturePos() == 0 && i == pol.size() - 1)
                p3 = a;
            if (pol.getTexturePos() != 0 && i == pol.getTexturePos() - 1)
                p3 = a;
            if (pol.size() == 4)
            {
                if (i == (pol.getTexturePos() + 2) % pol.size())
                    p4 = a;
            }
        }
        if (a.y() < ymin)
            ymin = a.y();
        if (a.y() > ymax)
            ymax = a.y();
    }
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
        point b2 = pol[(i+1)%pol.size()];
        point a2 = this->new_point(b2);
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
    line2D w1(p1.x(), p1.y(), p3.x(), p3.y());
    line2D h1(p1.x(), p1.y(), p2.x(), p2.y());
    line2D w2(p2.x(), p2.y(), p4.x(), p4.y());
    line2D h2(p3.x(), p3.y(), p4.x(), p4.y());
    for (size_t y = 0; y <= ymax - ymin; y++)
    {
        if (xmax[y] >= this->width())
            continue;

        double d = dmin[y];
        size_t count = xmax[y] - xmin[y];
        double dd;
        if (count != 0)
            dd = (dmax[y] - dmin[y])/count;
        else
            dd = 0;
        for (uint x = xmin[y]; x <= xmax[y]; x++)
        {
            double _x = -1, _y = -1;

            rgb col;
            if (!pol.isTexture())
            {
                col = _color;
            }
            else
            {
                if (w1.isParallel(w2))
                {
                    if (h1.isParallel(h2))
                    {
                        line2D pw(x, y + ymin, x + p3.x() - p1.x(), y + ymin + p3.y() - p1.y());
                        line2D ph(x, y + ymin, x + p2.x() - p1.x(), y + ymin + p2.y() - p1.y());
                        point px = ph^w1;
                        point py = pw^h1;
                        _x = (px - p1).length()/(p3 - p1).length();
                        _y = (py - p1).length()/(p2 - p1).length();
                    }
                    else
                    {
                        point p = h1^h2;
                        line2D pw(x, y + ymin, x + p3.x() - p1.x(), y + ymin + p3.y() - p1.y());
                        line2D ph(x, y + ymin, p.x(), p.y());
                        point px = ph^w1;
                        point py = pw^h1;
                        _x = (px - p1).length()/(p3 - p1).length();
                        _y = (py - p1).length()/(p2 - p1).length();
                    }
                }
                else
                {
                    point _p = w1^w2;
                    if (h1.isParallel(h2))
                    {
                        line2D pw(x, y + ymin, _p.x(), _p.y());
                        line2D ph(x, y + ymin, x + p2.x() - p1.x(), y + ymin + p2.y() - p1.y());
                        point px = ph^w1;
                        point py = pw^h1;
                        _x = (px - p1).length()/(p3 - p1).length();
                        _y = (py - p1).length()/(p2 - p1).length();
                    }
                    else
                    {
                        point _p2 = h1^h2;
                        line2D pw(x, y + ymin, _p.x(), _p.y());
                        line2D ph(x, y + ymin, _p2.x(), _p2.y());
                        point px = ph^w1;
                        point py = pw^h1;
                        _x = (px - p1).length()/(p3 - p1).length();
                        _y = (py - p1).length()/(p2 - p1).length();
                    }
                }
                if (_x >= 0 && _x <= 1 && _y >=0 && _y <= 1)
                    col = pol.getTexturePixel(_x, _y);
                else
                    col = _color;
            }
            setPixel(x, y+ymin, col, (size_t)d);
            d += dd;
        }

    }
}
