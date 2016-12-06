#include "line.h"

line::line(const point &p1, const point &p2, einput_line state){
    drawing = FRAME;
    _p1 = p1;
    _p2 = (state == SECOND_POINT) ? p2 : p1 + p2;
}


void line::set(const point& p1, const point& p2, einput_line state){
    _p1 = p1;
    _p2 = (state == SECOND_POINT) ? p2 : p1 + p2;
}


void line::set_point_1(const point& p){
    _p1 = p;
}

void line::set_point_2(const point& p){
    _p2 = p;
}

double line::length() const{
    return (_p1 - _p2).length();
}

const point& line::point_1() const{
    return _p2;
}

const point& line::point_2() const{
    return _p2;
}

point line::vector() const{
    point p(_p2 - _p1);
    p.normalization();
    return p;
}

void line::draw(Z_buffer_base *buf, const camera_base *cam) const{
    point c1 = _p1.project(buf, cam);
    point c2 = _p2.project(buf, cam);
    point b1 = _p1.camera(cam);
    point b2 = _p2.camera(cam);
    int x1 = c1.x(), x2 = c2.x();
    int y1 = c1.y(), y2 = c2.y();
    double d1 = (b1 - point(500, 0, 0)).length();
    double d2 = (b2 - point(500, 0, 0)).length();
    if (x1 == x2 && y1 == y2) {
        buf->setPixel(x1, x2, QColor(Qt::black), d1);
        return;
    }
    int x = fabs(x1 - x2);
    int y = fabs(y1 - y2);
    int count = (x >= y) ? x : y;
    double dx = (double)(x2 - x1) / count;
    double dy = (double)(y2 - y1) / count;
    double dd = (d2 - d1) / count;
    double _x = x1, _y = y1, _d = d1;
    QColor color(Qt::black);
    for (int i = 0; i <= count; i++) {
        buf->setPixel((int)_x, (int)_y, color, (size_t)_d);
        _x += dx;
        _y += dy;
        _d += dd;
    }
}
