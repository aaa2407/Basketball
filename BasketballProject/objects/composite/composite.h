#ifndef COMPOSITE_H
#define COMPOSITE_H

#include"mutable_array/marray.h"
#include "objects/object_base/object.h"

class composite : public object_base
{
public:
    composite(const char* name = NULL);

    bool isComposite() const;
    void transform(const transform_base& matr);

    void setColor(QColor color);
    void setOutwardNormal(bool ok);

    void draw(Z_buffer_base* buf, const camera_base*cam) const;

    void add(object* obj);
    void add(composite* obj);

    virtual marray<polygon> createParallelObject(double radius) const;

    object* findObject(const char* name);
    composite* findComposite(const char* name);

    void output() const;

protected:
    marray<object*> _objects;
    marray<composite*> _composites;
};

#endif // COMPOSITE_H
