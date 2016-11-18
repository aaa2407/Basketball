#ifndef DRAWINGSHADING_H
#define DRAWINGSHADING_H

#include "drawing\drawing3D_base\drawing3d_base.h"
#include "line\line2d.h"

class drawingShading : public drawing3Dbase
{
public:
    drawingShading(size_t width, size_t height, size_t max_depth = 3000, QColor back = QColor(Qt::white));

    void draw(const polygon& pol);

    void draw(const object_base& obj);
};

#endif // DRAWINGSHADING_H
