#ifndef POLYGON_H
#define POLYGON_H

#include "mutable_array\marray.h"
#include "point\point.h"
#include "geom_operations\operations.h"
#include "error_polygon.h"
#include "picture\picture.h"
#include "drawing/drawing_object.h"
#include "line/line2d.h"

class polygon : public marray<point>, public drawing_object
{
public:
    polygon();

    void changeNormal();
    point normal() const;
    plane get_plane() const;

    void setTexture(picture* pic = NULL);
    void setTexturePos(size_t index);
    color::rgb getTexturePixel(double x, double y) const;
    bool isTexture() const;
    size_t getTexturePos() const;
    size_t getTextureWidth() const;
    size_t getTextureHeight() const;

    void draw(Z_buffer *, const camera_base *) const;

protected:
    void drawFrame(Z_buffer *, const camera_base *) const;
    void drawShading(Z_buffer *, const camera_base *) const;
    void drawTexture(Z_buffer *, const camera_base *) const;

    bool napr;
    picture* _pic;
    size_t _num;
};

#endif // POLYGON_H
