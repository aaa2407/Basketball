#include "object_base.h"

object_base::object_base() : _outward_normal(true)
{ }

void object_base::setOutwardNormal(bool ok){
    _outward_normal = ok;
}

bool object_base::outwardNormal() const{
    return _outward_normal;
}

bool object_base::setConnect()
{
    _connect.setSize(_vertex.size());
    for (size_t i = 0; i < _polygons.size(); i++){
        for (size_t j = 0; j < _polygons[i].size(); j++){
            _connect[_polygons[i][j]].add(i);
        }
    }
    for (size_t i = 0; i < _connect.size(); i++)
    {
        if (_connect[i].size() != 3)
            return false;
        if (_connect[i][0] == _connect[i][1] ||
            _connect[i][0] == _connect[i][2] ||
            _connect[i][1] == _connect[i][2])
                return false;
    }
    return true;
}

polygon object_base::getPolygon(size_t index) const
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

size_t object_base::getPolygonCount() const
{
    return _polygons.size();
}

const point& object_base::centre() const
{
    return _centre;
}
