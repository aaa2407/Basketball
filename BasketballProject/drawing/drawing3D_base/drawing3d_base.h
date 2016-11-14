#ifndef DRAWING3D_BASE_H
#define DRAWING3D_BASE_H

#include "drawing\z-buffer\z-buffer.h"
#include "camera\camera.h"
#include "polygon\polygon.h"
#include "objects\parallelepiped\paral.h"
#include "rgb\rgb.h"

class drawing3Dbase : public Z_buffer, public camera
{
public:
    drawing3Dbase(size_t width, size_t height, size_t max_depth = 3000, QColor back = QColor(Qt::white));

    void draw(const point& p);
    void draw(const point& p1, const point& p2);

    virtual void draw(const polygon& pol) = 0;

    virtual void draw(const object_base& obj);

    void setPenColor(color::rgb color);

protected:
    color::rgb _color;
    int x_2d(double x) const;
    int y_2d(double y) const;
};

#endif // DRAWING3D_BASE_H
