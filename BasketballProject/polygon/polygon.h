#ifndef POLYGON_H
#define POLYGON_H

#include "mutable_array\marray.h"
#include "point\point.h"
#include "geom_operations\operations.h"
#include "error_polygon.h"
#include "picture\picture.h"
#include "drawing/drawing_object.h"
#include "line/line2d.h"
#include "transform_matrix/transform_matrix.h"
#include "line/line.h"

class polygon : public marray<point>, public drawing_object
{
public:
    polygon();

    void changeNormal();
    point normal() const;
    plane get_plane() const;

    void add(point value);

    void setColor(rgb color);
    void setTexture(picture* pic = NULL);
    void setTexturePos(size_t index);
    color::rgb getTexturePixel(double x, double y) const;
    bool isTexture() const;
    size_t getTexturePos() const;
    size_t getTextureWidth() const;
    size_t getTextureHeight() const;

    void draw(Z_buffer_base *, const camera_base *) const;

    void setNormals(const array<point>& arr);

protected:
    void drawFrame(Z_buffer_base *, const camera_base *) const;
    void drawTexture(Z_buffer_base *, const camera_base *) const;

    int findYmin() const;
    int findYmax() const;
    array<point> findTextureFrame() const;

protected:
    array<point> _normals;
    rgb  _color;
    bool napr;
    picture* _pic;
    size_t _num;
};

#endif // POLYGON_H
