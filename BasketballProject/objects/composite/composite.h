#ifndef COMPOSITE_H
#define COMPOSITE_H

#include"mutable_array/marray.h"
#include "objects/object_base/object.h"

class composite : public object_base
{
public:
    composite(const char* name = NULL);

    bool isComposite() const {return true; }

    void transform(const transform_base& matr){
        for (size_t i = 0; i < _objects.size(); i++){
            _objects[i]->transform(matr);
        }
        for (size_t j = 0; j < _composites.size(); j++){
            _composites[j]->transform(matr);
        }
    }

    void setObjectColor(QColor color){
        for (size_t i = 0; i < _objects.size(); i++){
            _objects[i]->setObjectColor(color);
        }
        for (size_t j = 0; j < _composites.size(); j++){
            _composites[j]->setObjectColor(color);
        }
    }

    void setOutwardNormal(bool ok){
        for (size_t i = 0; i < _objects.size(); i++){
            _objects[i]->setOutwardNormal(ok);
        }
        for (size_t j = 0; j < _composites.size(); j++){
            _composites[j]->setOutwardNormal(false);
        }
    }

    void draw(Z_buffer* buf, const camera_base*cam) const{
        for (size_t i = 0; i < _objects.size(); i++){
            _objects[i]->draw(buf, cam);
        }
        for (size_t j = 0; j < _composites.size(); j++){
            _composites[j]->draw(buf, cam);
        }
    }

    void add(object* obj){
        _objects.add(obj);
    }

    void add(composite* obj){
        _composites.add(obj);
    }

protected:
    marray<object*> _objects;
    marray<composite*> _composites;
};

#endif // COMPOSITE_H
