#include "z-buffer_detachment.h"

Z_buffer_Detachment::Z_buffer_Detachment(Z_buffer* buf)
   : _buf(buf)
{}

void Z_buffer_Detachment::setPixel(int x, int y, color::rgb color, size_t depth){
    if (_buf == NULL)
        return;
    if (x < 0 || y < 0 || (size_t)x >= this->height() || (size_t)y >= this->width()){
        return;
    }
    if (depth < _buf->depth(x, y))
    {
        struct pixel_det p;
        p.pix.depth = depth;
        p.pix.color.red = color.red;
        p.pix.color.blue = color.blue;
        p.pix.color.green = color.green;
        p.x = x;
        p.y = y;
        _pixels.add(p);
    }
}

void Z_buffer_Detachment::setPixel(int x, int y, QColor col, size_t depth){
    this->setPixel(x, y, color::get_rgb(col), depth);
}

void Z_buffer_Detachment::clear(){
    _pixels.clear();
}

size_t Z_buffer_Detachment::width() const{
    return (_buf != NULL) ? _buf->width() : 0;
}

size_t Z_buffer_Detachment::height() const{
    return (_buf != NULL) ? _buf->height() : 0;
}

size_t Z_buffer_Detachment::maxDepth() const{
    return (_buf != NULL) ? _buf->maxDepth() : 0;
}

QPixmap Z_buffer_Detachment::createPixmap() const{
    if (_buf == NULL)
        return QPixmap();
    QPixmap pixmap(this->width(), this->height());
    pixmap.fill(QColor(255, 255, 255 ,0));
    QPainter *painter = new QPainter(&pixmap);
    for (size_t i = 0; i < _pixels.size(); i++){
        struct pixel p = _pixels[i].pix;
        if (p.depth >= 3000)
            continue;
        painter->setPen(QColor(p.color.red, p.color.green, p.color.blue));
        painter->drawPoint(_pixels[i].x, _pixels[i].y);
    }
    delete painter;
    QBitmap BM = pixmap.createMaskFromColor(QColor(255, 255, 255));
    pixmap.setMask(BM);
    return pixmap;
}

size_t Z_buffer_Detachment::size() const{
    return _pixels.size();
}

size_t Z_buffer_Detachment::depth(size_t index) const{
    return _pixels[index].pix.depth;
}
