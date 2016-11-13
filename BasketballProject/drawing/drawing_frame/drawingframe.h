#ifndef DRAWINGFRAME_H
#define DRAWINGFRAME_H

#include "drawing\drawing3D_base\drawing3d_base.h"

class drawingFrame : public drawing3Dbase
{
public:
    drawingFrame(size_t width, size_t height, size_t max_depth = 3000, QColor back = QColor(Qt::white));

    void draw(const polygon& pol);

    void setPenColor(QColor pen);

private:
    QColor _pen;
};

#endif // DRAWINGFRAME_H
