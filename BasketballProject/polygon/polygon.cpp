#include "polygon.h"

polygon::polygon()
{
    napr = true;
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

plane polygon::get_plane() const
{
    if (!operations::isPolygon(*this))
    {
        errPolygon::errorNormal();
    }
    plane p((*this)[0], (*this)[1], (*this)[2]);
    if (!napr)
        p.negation();
    return p;
}



void polygon::setTexture(picture* pic)
{
    _pic = pic;

}

void polygon::setTexturePos(size_t index)
{
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
        col = _pic->getPixel(x*(_pic->width()-2)+1, y*(_pic->height()-2)+1);
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

