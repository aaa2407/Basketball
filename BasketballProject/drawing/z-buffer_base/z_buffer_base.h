#ifndef Z_BUFFER_BASE_H
#define Z_BUFFER_BASE_H

#include <QPixmap>
#include "rgb/rgb.h"

class Z_buffer_base{
public:
    virtual void setPixel(int x, int y, color::rgb color, size_t depth) = 0;
    virtual void setPixel(int x, int y, QColor col, size_t depth) = 0;

    virtual void clear() = 0;

    virtual size_t width() const = 0;
    virtual size_t height() const = 0;

    virtual size_t maxDepth() const = 0;
    virtual QPixmap createPixmap() const = 0;
};

#endif // Z_BUFFER_BASE_H
