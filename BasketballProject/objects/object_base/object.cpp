#include "object.h"

object::object() : _outward_normal(true)
{
    drawing = TEXTURE;
    deleteRobert = false;
}


const char* object::name() const
{
    return _name;
}


void object::setName(const char* n)
{
    _name = (char*)n;
}

void object::draw(Z_buffer_base *buf, const camera_base* cam) const{
    for (size_t i = 0; i < this->getPolygonCount(); i++)
        {
            polygon pol = this->getPolygon(i);
            pol.drawing = this->drawing;
            if (_pol_text[i].ok == true){
                pol.setColor(_pol_text[i]._col);
            }
            else {
                pol.setColor(this->_color);
            }
            pol.setTexture(this->getPolygonTexture(i));
            pol.setTexturePos(this->getPolygonTexturePos(i));
            array<double> a = pol.normal().toArray();
            a = a * TransformMatrix::rotateZ(cam->rotate());
            a = a * TransformMatrix::rotateY(cam->incline());
            point p(a);
            if (!this->outwardNormal() || deleteRobert){
                double r = p * point(-1, 0, 0);
                if (r >= 0) {
                    pol.draw(buf, cam);
                }
            }
            else
                pol.draw(buf, cam);
        }
}


void object::setOutwardNormal(bool ok){
    _outward_normal = ok;
}

bool object::outwardNormal() const{
    return _outward_normal;
}

bool object::setConnect()
{
    _connect.setSize(_vertex.size());
    for (size_t i = 0; i < _polygons.size(); i++){
        for (size_t j = 0; j < _polygons[i].size(); j++){
            _connect[_polygons[i][j]].add(i);
        }
    }
    return true;
}

void object::initColors()
{
    _pol_text.setSize(_polygons.size());
    for (size_t i = 0; i < _pol_text.size(); i++)
    {
        _pol_text[i].ok  = false;
        _pol_text[i]._col.blue  = 0;
        _pol_text[i]._col.red   = 0;
        _pol_text[i]._col.green = 0;
        _pol_text[i]._pic = NULL;
        _pol_text[i]._pic_pos = 0;
    }
}

polygon object::getPolygon(size_t index) const
{
    polygon pol;
    for (size_t i = 0; i < _polygons[index].size(); i++)
    {
        pol.add(_vertex[_polygons[index][i]]);
    }
    double value = pol.get_plane().value(_centre);
    if ((value < 0 && _outward_normal) || (value > 0 && !_outward_normal))
    {
        pol.changeNormal();
    }
    return pol;
}

color::rgb object::getPolygonColor(size_t index) const
{
    return _pol_text[index]._col;
}


void object::setPolygonColor(size_t index, QColor col)
{
    _pol_text[index].ok = true;
    _pol_text[index]._col = color::get_rgb(col);
}

void object::setColor(QColor color)
{
    _color = get_rgb(color);
}

void object::setPolygonPicture(size_t index, picture* pic)
{
    _pol_text[index]._pic = pic;
}

void object::setPolygonPicturePos(size_t index, size_t pos)
{
    if (index < _pol_text.size())
    {
        _pol_text[index]._pic_pos = pos;
    }
}

void object::transform(const transform_base& matr)
{
    for (size_t i = 0; i < _vertex.size(); i++)
    {
        _vertex[i] = point(_vertex[i].toArray()*matr);
    }
    _centre = point(_centre.toArray()*matr);
}

size_t object::getPolygonCount() const
{
    return _polygons.size();
}

picture* object::getPolygonTexture(size_t index) const
{
    return _pol_text[index]._pic;
}

size_t object::getPolygonTexturePos(size_t index) const
{
    return _pol_text[index]._pic_pos;
}

const point& object::centre() const
{
    return _centre;
}
