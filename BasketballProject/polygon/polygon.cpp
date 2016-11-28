#include "polygon.h"

polygon::polygon()
{
    napr = true;
    drawing = FRAME;
}


void polygon::changeNormal()
{
    napr = !napr;
}


point polygon::normal() const
{
    if (!operations::isPolygon(*this))
    {
        errPolygon::errorNormal();
    }
    point p = operations::normal((*this)[0], (*this)[1], (*this)[2]);
    if (!napr)
        p = -p;
    return p;
}

plane polygon::get_plane() const{
    if (!operations::isPolygon(*this))
    {
        errPolygon::errorNormal();
    }
    plane p((*this)[0], (*this)[1], (*this)[2]);
    if (!napr)
        p.negation();
    return p;
}

void polygon::setColor(rgb color){
    _color = color;
}

void polygon::setTexture(picture* pic){
    _pic = pic;
}

void polygon::setTexturePos(size_t index){
    if (index >= this->size())
        throw errPolygon::errorIncorrectIndex();
    this->_num = index;
}


color::rgb polygon::getTexturePixel(double x, double y) const
{
    if (_pic == NULL)
        throw errPolygon::errorPicture();
    rgb col;
    if (x >= 0 && y >= 0 && x <= 1 && y <= 1)
    {
        col = _pic->getPixel(x*(_pic->width()-3)+1, y*(_pic->height()-3)+1);
    }
    else
    {
        col.green = 0;
        col.red = 0;
        col.blue = 0;
    }
    return col;
}

bool polygon::isTexture() const
{
    if (this->_pic == NULL)
        return false;
    else
        return true;
}

size_t polygon::getTexturePos() const
{
    return this->_num;
}

size_t polygon::getTextureWidth() const
{
    if (_pic == NULL)
        throw errPolygon::errorPicture();
    return this->_pic->width();
}

size_t polygon::getTextureHeight() const
{
    if (_pic == NULL)
        throw errPolygon::errorPicture();
    return this->_pic->height();
}

void polygon::draw(Z_buffer_base *buf, const camera_base *cam) const
{
    if (!operations::isConvexPolygon(*this) || this->size() < 3)
    {
        return;
    }
    switch(drawing)
    {
        case FRAME:
            drawFrame(buf, cam);
        break;
        case TEXTURE:
            drawTexture(buf, cam);
        break;
    }
}

void polygon::drawFrame(Z_buffer_base *buf, const camera_base *cam) const
{
    for (size_t i = 0; i < this->size(); i++)
    {
        point p1 = (*this)[i];
        point p2 = (*this)[(i+1)%this->size()];
        point c1 = point(p1.toArray()*cam->get());
        point a1 = c1.to2D();
        a1.set_x(a1.x() + buf->width()/2);
        a1.set_y(-a1.y() + buf->height()/2);
        point c2(p2.toArray()*cam->get());
        point a2 = c2.to2D();
        a2.set_x(a2.x() + buf->width()/2);
        a2.set_y(-a2.y() + buf->height()/2);
        int x1 = a1.x();
        int x2 = a2.x();
        int y1 = a1.y();
        int y2 = a2.y();
        double d1 = (c1 - point(500, 0, 0)).length();
        double d2 = (c2 - point(500, 0, 0)).length();
        if (x1 == x2 && y1 == y2)
        {
            buf->setPixel(x1, x2, this->_color, d1);
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
            buf->setPixel((int)_x, (int)_y, _color, (size_t)_d);
            _x += dx;
            _y += dy;
            _d += dd;
        }
    }
}


void polygon::drawTexture(Z_buffer_base *buf, const camera_base *cam) const
{
    point p1, p2, p3, p4;
    double ymin = buf->height();
    double ymax = 0;
    for (size_t i = 0; i < this->size(); i++)
    {
        point a = point((*this)[i].toArray()*cam->get());
        a = a.to2D();
        a.set_x(a.x() + buf->width()/2);
        a.set_y(-a.y() + buf->height()/2);
        if (this->isTexture())
        {
            if (i == this->getTexturePos())
                p1 = a;
            if (i == (this->getTexturePos() + 1) % this->size())
                p2 = a;
            if (this->getTexturePos() == 0 && i == this->size() - 1)
                p3 = a;
            if (this->getTexturePos() != 0 && i == this->getTexturePos() - 1)
                p3 = a;
            if (this->size() == 4) {
                if (i == (this->getTexturePos() + 2) % this->size())
                    p4 = a;
            }
            else {
                p4 = p3 + p2 - p1;
            }
        }
        if (a.y() < ymin)
            ymin = a.y();
        if (a.y() > ymax)
            ymax = a.y();
    }
    if (ymax >= buf->height()){
        ymax = buf->height() - 1;
    }
    int xmin[(size_t)ymax - (size_t)ymin + 1];
    int xmax[(size_t)ymax - (size_t)ymin + 1];
    point pmin[(size_t)ymax - (size_t)ymin + 1];
    point pmax[(size_t)ymax - (size_t)ymin + 1];
    for (size_t i = 0; i <= ymax - ymin; i++)
    {
        xmax[i] = 0;
        xmin[i] = buf->width();
    }
    for (size_t i = 0; i < this->size(); i++)
    {
        point b1 = (*this)[i];
        point c1 = point(b1.toArray()*cam->get());
        point a1 = c1;
        a1 = a1.to2D();
        a1.set_x(a1.x() + buf->width()/2);
        a1.set_y(-a1.y() + buf->height()/2);
        point b2 = (*this)[(i+1)%this->size()];
        point c2 = point(b2.toArray()*cam->get());
        point a2 = c2;
        a2 = a2.to2D();
        a2.set_x(a2.x() + buf->width()/2);
        a2.set_y(-a2.y() + buf->height()/2);
        double _y0 = (a1.y() < a2.y()) ? a1.y() : a2.y();
        double _y1 = (a1.y() < a2.y()) ? a2.y() : a1.y();
        double _x0 = (a1.y() < a2.y()) ? a1.x() : a2.x();
        double _x1 = (a1.y() < a2.y()) ? a2.x() : a1.x();
        point _p0 = (a1.y() < a2.y()) ? c1 : c2;
        point _p1 = (a1.y() < a2.y()) ? c2 : c1;
        for (double y = _y0; y <= _y1; y += 1)
        {
            double x = _x0 + (_x1 - _x0)*((y - _y0)/(_y1 - _y0));
            point  p = _p0 + (_p1 - _p0)*((y - _y0)/(_y1 - _y0));
            if (x < xmin[(size_t)y - (size_t)ymin]){
                xmin[(size_t)y - (size_t)ymin] = (int)x;
                pmin[(size_t)y - (size_t)ymin] = p;
                if (xmin[(size_t)y - (size_t)ymin] < 0)
                    xmin[(size_t)y - (size_t)ymin] = 0;
            }
            if (x > xmax[(size_t)y - (size_t)ymin])
            {
                xmax[(size_t)y - (size_t)ymin] = (int)x;
                pmax[(size_t)y - (size_t)ymin] = p;
                if (xmax[(size_t)y - (size_t)ymin] >= buf->width())
                    xmax[(size_t)y - (size_t)ymin] = 0;
            }
        }
    }
    line2D w1, h1, w2, h2;
    if (this->isTexture())
    {
        w1.set(p1.x(), p1.y(), p3.x(), p3.y());
        h1.set(p1.x(), p1.y(), p2.x(), p2.y());
        w2.set(p2.x(), p2.y(), p4.x(), p4.y());
        h2.set(p3.x(), p3.y(), p4.x(), p4.y());
    }
    //point s = point(0, 0, 500);
    point c = point(500, 0, 0);
    for (size_t y = 0; y <= ymax - ymin; y++)
    {

        if (xmax[y] >= buf->width())
            continue;
        size_t count = xmax[y] - xmin[y];
        point p_ = pmin[y];
        point pp = (count != 0) ? (pmax[y] - pmin[y])*(1/((double)count)) : point(0, 0 ,0);

        for (uint x = xmin[y]; x <= xmax[y]; x++)
        {
            double _x = -1, _y = -1;

            rgb col;
            if (!this->isTexture()) {
                point n = this->normal();
                array<double> arr = n.toArray();
                arr = arr*TransformMatrix::rotateZ(cam->rotate());
                arr = arr*TransformMatrix::rotateY(cam->incline());

                n = point(arr);
                col = operations::Fong(_color, p_, n, c, c);
            }
            else {
                line2D pw, ph;
                if (h1.isParallel(h2)) {
                    ph.set(x, y + ymin, x + p2.x() - p1.x(), y + ymin + p2.y() - p1.y());
                }
                else {
                    point p = h1^h2;
                    ph.set(x, y + ymin, p.x(), p.y());
                }
                if (w1.isParallel(w2)) {
                    pw.set(x, y + ymin, x + p3.x() - p1.x(), y + ymin + p3.y() - p1.y());
                }
                else {
                    point p = w1^w2;
                    pw.set(x, y + ymin, p.x(), p.y());
                }
                point px = ph^w1;
                point py = pw^h1;
                _x = (px - p1).length()/(p3 - p1).length();
                _y = (py - p1).length()/(p2 - p1).length();
                if (_x >= 0 && _x <= 1 && _y >=0 && _y <= 1)
                    col = this->getTexturePixel(_x, _y);
                else
                    col = _color;

                point n = this->normal();
                array<double> arr = n.toArray();
                arr = arr * TransformMatrix::rotateZ(cam->rotate());
                arr = arr * TransformMatrix::rotateY(cam->incline());
                n = point(arr);
                col = operations::Fong(col, p_, n, c, c);
            }
            buf->setPixel(x, y+ymin, col, (p_ - point(500, 0, 0)).length());
            p_ += pp;
        }

    }
}
