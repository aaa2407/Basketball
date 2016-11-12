#include "z-buffer.h"


Z_buffer::Z_buffer(size_t width, size_t height, size_t max, QColor back)
    : matrix<struct pixel>(height, width)
{
   MaxDepth = max;
   _background = back;
   for (size_t i = 0; i < rowCount(); i++)
   {
       for (size_t j = 0; j < columnCount(); j++)
       {
           struct pixel p;
           p.depth = MaxDepth;
           p.red = back.red();
           p.blue = back.blue();
           p.green = back.green();
           (*this)[i][j] = p;
       }
   }
}

Z_buffer::Z_buffer(const Z_buffer& copy)
    : matrix<struct pixel>(copy.height(), copy.width())
{
    MaxDepth = copy.MaxDepth;
    _background = copy._background;
    for (size_t i = 0; i < rowCount(); i++)
    {
        for (size_t j = 0; j < columnCount(); j++)
        {
            (*this)[i][j] = copy.value(i, j);
        }
    }
}

void Z_buffer::set(size_t width, size_t height, size_t max, QColor colour)
{
    Z_buffer(width, height, max, colour);
}

void Z_buffer::set(const Z_buffer& copy)
{
    set(copy.width(), copy.height(), copy.maxDepth(), copy.background());
}

Z_buffer& Z_buffer::operator=(const Z_buffer& copy)
{
    this->set(copy);
    return *this;
}

void Z_buffer::setBackgroundColor(QColor back)
{
    _background = back;
}

void Z_buffer::setMaxDepth(size_t depth)
{
    MaxDepth = depth;
}

void Z_buffer::setPixel(int x, int y, char r, char g, char b, size_t depth)
{
    if (x < 0 || y < 0 || (size_t)x > columnCount() || (size_t)y > rowCount())
    {
        return;
        //throw errZ_buffer::errorPixel();
    }
    if (depth < value(y, x).depth)
    {
        struct pixel p;
        p.depth = depth;
        p.red = r;
        p.blue = b;
        p.green = g;
        (*this)[y][x] = p;
    }
}



void Z_buffer::setPixel(int x, int y, QColor col, size_t depth)
{
    if (x < 0 || y < 0 || (size_t)x >= columnCount() || (size_t)y >= rowCount())
    {
        return;
        //throw errZ_buffer::errorPixel();
    }
    if (depth < value(y, x).depth)
    {
        struct pixel p;
        p.depth = depth;
        p.red = col.red();
        p.blue = col.blue();
        p.green = col.green();
        (*this)[y][x] = p;
    }
}

void Z_buffer::clear()
{
    struct pixel p;
    p.depth = MaxDepth;
    p.blue = 0;
    p.red = 0;
    p.green = 0;
    for (size_t i = 0 ; i < rowCount(); i++)
        for (size_t j = 0 ; j < columnCount(); j++)
            if ((*this)[i][j].depth < MaxDepth)
            {
                (*this)[i][j] = p;
            }
}

size_t Z_buffer::width() const
{
    return columnCount();
}

size_t Z_buffer::height() const
{
    return rowCount();
}

QColor Z_buffer::background() const
{
    return _background;
}

size_t Z_buffer::maxDepth() const
{
    return MaxDepth;
}


QColor Z_buffer::getPixel(int x, int y) const
{
    if (x < 0 || y < 0)
    {
        return 3000;
    }
    if ((size_t)x > columnCount() && (size_t)y > rowCount())
    {
        throw err_Z_buffer::errorPixel();
    }
    return QColor(value(y, x).red, value(y, x).green, value(y, x).blue);
}

size_t Z_buffer::depth(int x, int y) const
{
    if (x < 0 || y < 0)
        return 3000;
    if ((size_t)x > columnCount() || (size_t)y > rowCount())
    {
        throw err_Z_buffer::errorPixel();
    }
    return value(y, x).depth;
}

QPixmap Z_buffer::createPixmap() const
{
    QPixmap pixmap(this->columnCount(), this->rowCount());
    QPainter painter(&pixmap);
    pixmap.fill(_background);
    for (size_t i = 0; i < columnCount(); i++)
        for (size_t j = 0; j < rowCount(); j++)
        {
            struct pixel p = (*this)[j][i];
            if (p.depth < MaxDepth)
            {
                painter.setPen(QColor(p.red, p.green, p.blue));
                painter.drawPoint(i, j);
            }
        }
    return pixmap;
}
