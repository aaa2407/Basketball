#include "polygon.h"

polygon::polygon()
{
    napr = true;
    drawing = FRAME;
}


void polygon::changeNormal()
{
    napr = !napr;
}


point polygon::normal() const
{
    if (!operations::isPolygon(*this)) {
        errPolygon::errorNormal();
    }
    point p = operations::normal((*this)[0], (*this)[1], (*this)[2]);
    if (!napr)
        p = -p;
    return p;
}

plane polygon::get_plane() const{
    if (!operations::isPolygon(*this))
    {
        errPolygon::errorNormal();
    }
    plane p((*this)[0], (*this)[1], (*this)[2]);
    if (!napr)
        p.negation();
    return p;
}

void polygon::add(point value){
    marray<point>::add(value);
}

void polygon::setColor(rgb color){
    _color = color;
}

void polygon::setTexture(picture* pic){
    _pic = pic;
}

void polygon::setTexturePos(size_t index){
    if (index >= this->size())
        throw errPolygon::errorIncorrectIndex();
    this->_num = index;
}


color::rgb polygon::getTexturePixel(double x, double y) const
{
    if (_pic == NULL)
        throw errPolygon::errorPicture();
    rgb col;
    if (x >= 0 && y >= 0 && x <= 1 && y <= 1){
        col = _pic->getPixel(x*(_pic->width()-3)+1, y*(_pic->height()-3)+1);
    }
    else {
        col.green = 0;
        col.red = 0;
        col.blue = 0;
    }
    return col;
}

bool polygon::isTexture() const
{
    if (this->_pic == NULL)
        return false;
    else
        return true;
}

size_t polygon::getTexturePos() const{
    return _num;
}

size_t polygon::getTextureWidth() const
{
    if (_pic == NULL)
        throw errPolygon::errorPicture();
    return this->_pic->width();
}

size_t polygon::getTextureHeight() const
{
    if (_pic == NULL)
        throw errPolygon::errorPicture();
    return this->_pic->height();
}

void polygon::setNormals(const array<point>& arr){
    _normals = arr;
}

void polygon::draw(Z_buffer_base *buf, const camera_base *cam) const
{
    if (!operations::isConvexPolygon(*this) || this->size() < 3) {
        return;
    }
    switch(drawing)
    {
        case FRAME:
            drawFrame(buf, cam);
        break;
        case TEXTURE:
            drawTexture(buf, cam);
        break;
    }
}

void polygon::drawFrame(Z_buffer_base *buf, const camera_base *cam) const
{
    for (size_t i = 0; i < this->size(); i++)
    {
        line _line((*this)[i], (*this)[(i+1)%this->size()]);
        _line.draw(buf, cam);
    }
}

int polygon::findYmin() const{
    int ymin = 3000;
    for (size_t i = 0; i < this->size(); i++) {
        point a = (*this)[i];
        if ((int)a.y() < ymin)
            ymin = (int)a.y();
    }
    return ymin;
}

int polygon::findYmax() const{
    int ymax = 0;
    for (size_t i = 0; i < this->size(); i++) {
        point a = (*this)[i];
        if ((int)a.y() > ymax)
            ymax = (int)a.y();
    }
    return ymax;
}

array<point> polygon::findTextureFrame() const{
    array<point> frame(4);
    int num1 = _num % this->size();
    int num4 = (num1 > 0) ? num1 - 1 : this->size() - 1;
    int num2 = (num1  < (int)this->size() - 1) ? num1 + 1 : 0;
    frame[0] = (*this)[num1];
    frame[1] = (*this)[num2];
    frame[3] = (*this)[num4];
    if (this->size() == 3){
        frame[2] = (*this)[num4] + (*this)[num2] - (*this)[num1];
    }
    else {
        int num3 = (num1  < this->size() - 2) ? num1 + 2 : (num1 + 2) % this->size();
        frame[2] = (*this)[num3];
    }
    return frame;
}

void polygon::drawTexture(Z_buffer_base *buf, const camera_base *cam) const
{
    polygon proj;
    for (size_t i = 0; i < this->size(); i++){
        proj.add((*this)[i].project(buf, cam));
    }
    int ymin = proj.findYmin();
    ymin = (ymin < (int)buf->width() - 1) ? ymin : buf->width();
    int ymax = proj.findYmax();
    array<point> frame;
    if (this->isTexture()){
        frame.set(proj.findTextureFrame());
    }
    array<int> xmin(ymax - ymin + 1, buf->width()-1);
    array<int> xmax(ymax - ymin + 1, 0);
    array<point> pmin(ymax - ymin + 1);
    array<point> pmax(ymax - ymin + 1);
    array<point> nmin(ymax - ymin + 1);
    array<point> nmax(ymax - ymin + 1);
    for (size_t i = 0; i < this->size(); i++)
    {
        int i_1 = (i+1) % this->size();
        point c1 = (*this)[i].camera(cam);
        point a1 = proj[i];
        point n1 = _normals[i].camera_for_normal(cam);
        point c2 = (*this)[i_1].camera(cam);
        point a2 = proj[i_1];
        point n2 = _normals[i_1].camera_for_normal(cam);
        bool ok = (a1.y() < a2.y()) ? true : false;
        int _y0 = (ok) ? a1.y() : a2.y();
        int _y1 = (ok) ? a2.y() : a1.y();
        double _x0 = (ok) ? a1.x() : a2.x();
        double _x1 = (ok) ? a2.x() : a1.x();
        point _p0 = (ok) ? c1 : c2;
        point _p1 = (ok) ? c2 : c1;
        point _n0 = (ok) ? n1 : n2;
        point _n1 = (ok) ? n2 : n1;
        for (int y = _y0; y <= _y1; y += 1)
        {
            double x = _x0 + (_x1 - _x0)*((double)(y - _y0)/(double)(_y1 - _y0));
            point  p = _p0 + (_p1 - _p0)*((double)(y - _y0)/(double)(_y1 - _y0));
            point  n = _n0 + (_n1 - _n0)*((double)(y - _y0)/(double)(_y1 - _y0));
            if (x < xmin[y - ymin]){
                xmin[y - ymin] = (int)x;
                pmin[y - ymin] = p;
                nmin[y - ymin] = n;
            }
            if (x > xmax[y - ymin]) {
                xmax[y - ymin] = (int)x;
                pmax[y - ymin] = p;
                nmax[y - ymin] = n;
            }
        }
    }
    line2D w1, h1, w2, h2;
    if (this->isTexture()) {
        w1.set(frame[0].x(), frame[0].y(), frame[3].x(), frame[3].y());
        h1.set(frame[0].x(), frame[0].y(), frame[1].x(), frame[1].y());
        w2.set(frame[1].x(), frame[1].y(), frame[2].x(), frame[2].y());
        h2.set(frame[3].x(), frame[3].y(), frame[2].x(), frame[2].y());
    }
    point s = point(0, 0, 500);
    point c = point(500, 0, 0);
    //c = c.camera(cam);
    std::cout << std::endl;
    for (size_t y = 0; y <= ymax - ymin && y + ymin < buf->height(); y++)
    {
        size_t count = xmax[y] - xmin[y];
        point p_ = pmin[y];
        point pp = (count != 0) ? (pmax[y] - pmin[y])*(1/((double)count)) : point(0, 0 ,0);
        point n_ = nmin[y];
        point nn = (count != 0) ? (nmax[y] - nmin[y])*(1/((double)count)) : point(0, 0 ,0);
        int x_ = (xmin[y] < 0) ? 0 : xmin[y];
        for (int x = x_; x <= xmax[y] && x < buf->width(); x++)
        {
            double _x = -1, _y = -1;
            rgb col;
            if (!this->isTexture()) {
                col = _color;
            }
            else {
                line2D pw, ph;
                if (h1.isParallel(h2)) {
                    ph.set(x, y + ymin, x + frame[1].x() - frame[0].x(), y + ymin + frame[1].y() - frame[0].y());
                }
                else {
                    point p = h1^h2;
                    ph.set(x, y + ymin, p.x(), p.y());
                }
                if (w1.isParallel(w2)) {
                    pw.set(x, y + ymin, x + frame[3].x() - frame[0].x(), y + ymin + frame[3].y() - frame[0].y());
                }
                else {
                    point p = w1^w2;
                    pw.set(x, y + ymin, p.x(), p.y());
                }
                point vw = pw.vector();
                point hw = ph.vector();
                line2D uw(x, y + ymin, x + vw.x(), y + ymin + vw.y());
                line2D uh(x, y + ymin, x + hw.x(), y + ymin + hw.y());
                point px = ph^uw;
                point py = pw^uh;
                point px1 = uw^h1;
                point px2 = uw^h2;
                point py1 = uh^w1;
                point py2 = uh^w2;
                _x = (px - px1).length()/(px2 - px1).length();
                _y = (py - py1).length()/(py2 - py1).length();
                if (_x >= 0 && _x <= 1 && _y >=0 && _y <= 1)
                    col = this->getTexturePixel(_x, _y);
                else
                    col = _color;
            }
            col = operations::Fong(col, p_, n_, c, c);
            buf->setPixel(x, y+ymin, col, (p_ - c).length());
            p_ += pp;
            n_ += nn;
        }
    }
}
