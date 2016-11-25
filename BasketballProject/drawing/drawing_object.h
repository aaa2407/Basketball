#ifndef DRAWING_OBJECT_H
#define DRAWING_OBJECT_H

#include "z-buffer/z-buffer.h"
#include "camera/base_camera.h"

typedef enum{FRAME, SHADING, TEXTURE} edrawing;

class drawing_object
{
public:
    edrawing drawing;
    virtual void draw(Z_buffer*, const camera_base*) const = 0;
};

#endif // DRAWING_OBJECT_H
