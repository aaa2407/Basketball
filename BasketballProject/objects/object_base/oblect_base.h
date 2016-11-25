#ifndef OBLECT_BASE_H
#define OBLECT_BASE_H

#include "point/point.h"
#include "picture/picture.h"
#include "polygon/polygon.h"
#include "drawing/drawing_object.h"

class object_base :  public drawing_object
{
public:
    const char* name() const{
        return _name;
    }
    void setName(const char* name) {
        this->_name = (char*)name;
    }
    virtual bool isComposite() const = 0;
    virtual void transform(const transform_base& matr) = 0;
    virtual void setObjectColor(QColor color) = 0;
    virtual void setOutwardNormal(bool ok) = 0;
    virtual void draw(Z_buffer*, const camera_base*) const = 0;

protected:
    char* _name;
};

#endif // OBLECT_BASE_H
