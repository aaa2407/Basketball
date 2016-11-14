#ifndef Z_BUFFER_H
#define Z_BUFFER_H

#include <QColor>
#include <QPixmap>
#include <QPainter>

#include "matrix\matrix.h"
#include "error_z-buffer.h"
#include "rgb\rgb.h"

struct pixel
{
public:
    size_t depth;       // Глубина пикселя
    color::rgb    color;
};

class Z_buffer:  private matrix<struct pixel>
{
public:
    Z_buffer(size_t width = 1000, size_t height = 800, size_t max = 3000, QColor back = QColor(Qt::white));
    Z_buffer(const Z_buffer& copy);

    void set(size_t width = 1000, size_t height = 800, size_t max = 3000, QColor back = QColor(Qt::white));
    void set(const Z_buffer& copy);

    Z_buffer& operator=(const Z_buffer& copy);

    void setBackgroundColor(QColor back);
    void setMaxDepth(size_t depth);

    void setPixel(int x, int y, color::rgb color, size_t depth);
    void setPixel(int x, int y, QColor col, size_t depth);

    void clear();

    size_t width() const;
    size_t height() const;

    QColor background() const;
    size_t maxDepth() const;

    QColor getPixel(int x, int y) const;
    size_t depth(int x, int y) const;

    QPixmap createPixmap() const;

private:
    QColor _background;
    size_t MaxDepth;
};

#endif // Z_buffer_H
