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

void composite::output() const{
    for (size_t i = 0; i < _objects.size(); i++){
        std::cout << _objects[i]->name() << std::endl;
        for (size_t j = 0; j < _objects[i]->vertexCount(); j++){
            std::cout << _objects[i]->vertex(j) << "\t";
        }
        std::cout << std::endl << "-------" << std::endl;
    }
    for (size_t i = 0; i < _composites.size(); i++){
        _composites[i]->output();
    }
}

object* composite::findObject(const char* name){
    for (size_t i = 0; i < _objects.size(); i++){
        if (_objects[i]->name() == name){
            return _objects[i];
        }
    }
    object *obj = NULL;
    for (size_t i = 0; i < _composites.size(); i++){
         obj = _composites[i]->findObject(name);
         if (obj)
             break;
    }
    return obj;
}

composite* composite::findComposite(const char* name){
    if (this->name() == name)
        return this;
    composite *comp = NULL;
    for (size_t i = 0; i < _composites.size(); i++){
        comp = _composites[i]->findComposite(name);
        if (comp)
            break;
    }
    return comp;
}
