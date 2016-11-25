#ifndef Z_BUFFER_DETACHMENT_H
#define Z_BUFFER_DETACHMENT_H

#include "drawing/z-buffer/z-buffer.h"
#include "drawing/z-buffer/pixel.h"
#include <mutable_array/marray.h>
#include <QBitmap>

struct pixel_det{
    pixel pix;
    size_t x, y;
};

class Z_buffer_Detachment : public Z_buffer_base
{
public:
    Z_buffer_Detachment(Z_buffer* buf = NULL);

    void setPixel(int x, int y, color::rgb color, size_t depth);
    void setPixel(int x, int y, QColor col, size_t depth);

    void clear();

    size_t width() const;
    size_t height() const;

    size_t maxDepth() const;

    QColor getPixel(int x, int y) const;

    size_t depth(int x, int y) const;
    virtual QPixmap createPixmap() const;

private:
    Z_buffer *_buf;
    marray<struct pixel_det> _pixels;
};

#endif // Z_BUFFER_DETACHMENT_H
