#include "drawing3d_base.h"

drawing3Dbase::drawing3Dbase(size_t width, size_t height, size_t max_depth, QColor back)
    : Z_buffer(width, height, max_depth, back)
{
    this->clear();
}

void drawing3Dbase::draw(const point& p, QColor color)
{
    point a = this->new_point(p);
    point a1 = a.to2D();
    this->setPixel(x_2d(a1.x()), y_2d(a1.y()), color, distance(a));
}

void drawing3Dbase::draw(const point& p1, const point& p2, QColor color)
{
    point a1 = this->new_point(p1);
    point a2 = this->new_point(p2);
    point b1 = a1.to2D();
    point b2 = a2.to2D();
    int x1 = x_2d(b1.x());
    int x2 = x_2d(b2.x());
    int y1 = y_2d(b1.y());
    int y2 = y_2d(b2.y());
    double d1 = this->distance(a1);
    double d2 = this->distance(a2);
    if (x1 == x2 && y1 == y2)
    {
        this->setPixel(x1, x2, color, d1);
        return;
    }
    int x = fabs(x1 - x2);
    int y = fabs(y1 - y2);
    int count = (x >= y) ? x : y;
    double dx = (double)(x2 - x1) / count;
    double dy = (double)(y2 - y1) / count;
    double dd = (d2 - d1) / count;
    double _x = x1;
    double _y = y1;
    double _d = d1;

    for (int i = 0; i <= count; i++)
    {
        this->setPixel((int)_x, (int)_y, color, (size_t)_d);
        _x += dx;
        _y += dy;
        _d += dd;
    }
}

int drawing3Dbase::x_2d(double x) const
{
    return x + this->width()/2;
}

int drawing3Dbase::y_2d(double y) const
{
    return -y + this->height()/2;
}