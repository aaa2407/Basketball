#ifndef OBJECT_H
#define OBJECT_H

#include "objects\object_base\oblect_base.h"
#include "mutable_array\marray.h"
#include "transform_matrix\transform_matrix.h"

typedef struct{
    color::rgb _col;
    picture* _pic;
    size_t _pic_pos;
} spolygon;


class object : public object_base
{
public:
    object();

    const char* name() const;
    void setName(const char* n);

    bool isComposite() const { return false; }

    void draw(Z_buffer *buf, const camera_base* cam) const;

    virtual polygon getPolygon(size_t index) const;
    color::rgb getPolygonColor(size_t index) const;
    size_t  getPolygonCount() const;
    picture *getPolygonTexture(size_t index) const;
    size_t getPolygonTexturePos(size_t index) const;

    const point& centre() const;
    void setOutwardNormal(bool ok);
    bool outwardNormal() const;

    virtual void transform(const transform_base& matr);

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
    array<spolygon> _pol_text;
    point _centre;
    bool _outward_normal;
    char* _name;
};

#endif // OBJECT_H
