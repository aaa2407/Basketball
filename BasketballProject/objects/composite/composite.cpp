#include "composite.h"

composite::composite(const char *name)
{
    _name = (name != NULL) ? ((char*)name) : NULL;
}

bool composite::isComposite() const
{
    return true;
}

void composite::transform(const transform_base& matr){
    for (size_t i = 0; i < _objects.size(); i++){
        _objects[i]->transform(matr);
    }
    for (size_t j = 0; j < _composites.size(); j++){
        _composites[j]->transform(matr);
    }
}

void composite::setColor(QColor color){
    for (size_t i = 0; i < _objects.size(); i++){
        _objects[i]->setColor(color);
    }
    for (size_t j = 0; j < _composites.size(); j++){
        _composites[j]->setColor(color);
    }
}

void composite::setOutwardNormal(bool ok){
    for (size_t i = 0; i < _objects.size(); i++){
        _objects[i]->setOutwardNormal(ok);
    }
    for (size_t j = 0; j < _composites.size(); j++){
        _composites[j]->setOutwardNormal(false);
    }
}

void composite::draw(Z_buffer_base* buf, const camera_base*cam) const{
    for (size_t i = 0; i < _objects.size(); i++){
        _objects[i]->draw(buf, cam);
    }
    for (size_t j = 0; j < _composites.size(); j++){
        _composites[j]->draw(buf, cam);
    }
}


void composite::add(object* obj){
    _objects.add(obj);
}

void composite::add(composite* obj){
    _composites.add(obj);
}

marray<polygon> composite::createParallelObject(double radius) const
{
    marray<polygon> arr;
    for (size_t i = 0; i < this->_objects.size(); i++){
        marray<polygon> arr_2 = _objects[i]->createParallelObject(radius);
        for (size_t j = 0; j < arr_2.size(); j++){
            arr.add(arr_2[j]);
        }
    }
    for (size_t i = 0; i < this->_composites.size(); i++){
        marray<polygon> arr_2 = _composites[i]->createParallelObject(radius);
        for (size_t j = 0; j < arr_2.size(); j++){
            arr.add(arr_2[j]);
        }
    }
    return arr;
}
