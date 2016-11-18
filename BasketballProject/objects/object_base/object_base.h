#ifndef OBJECT_BASE_H
#define OBJECT_BASE_H

#include "point\point.h"
#include "mutable_array\marray.h"
#include "polygon\polygon.h"
#include "rgb\rgb.h"
#include "picture\picture.h"

typedef struct{
    color::rgb _col;
    picture* _pic;
    size_t _pic_pos;
} spolygon;

class object_base
{
public:
    object_base();

    polygon getPolygon(size_t index) const;
    color::rgb getPolygonColor(size_t index) const;
    size_t  getPolygonCount() const;
    picture *getPolygonTexture(size_t index) const;
    size_t getPolygonTexturePos(size_t index) const;

    const point& centre() const;
    void setOutwardNormal(bool ok);
    bool outwardNormal() const;

    void setPolygonColor(size_t index, QColor col);
    void setObjectColor(QColor color);
    void setPolygonPicture(size_t index, picture* pic);
    void setPolygonPicturePos(size_t index, size_t pos);

protected:
    bool setConnect();

protected:
    marray<point> _vertex;
    array<marray<size_t>> _connect;
    marray<marray<size_t>> _polygons;
    point _centre;
    bool _outward_normal;
    array<spolygon> _pol_text;
};

#endif // OBJECT_BASE_H
