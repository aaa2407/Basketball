#ifndef DRAWING3D_BASE_H
#define DRAWING3D_BASE_H

#include "drawing\z-buffer\z-buffer.h"
#include "camera\camera.h"
#include "polygon\polygon.h"

class drawing3Dbase : public Z_buffer, public camera
{
public:
    drawing3Dbase(size_t width, size_t height, size_t max_depth = 3000, QColor back = QColor(Qt::white));

    void draw(const point& p, QColor color = QColor(Qt::black));
    void draw(const point& p1, const point& p2, QColor color = QColor(Qt::black));

    virtual void draw(const polygon& pol) = 0;

    void setPenColor(QColor color);

private:
    int x_2d(double x) const;
    int y_2d(double y) const;
};

#endif // DRAWING3D_BASE_H