#ifndef DRAWING_OBJECT_H
#define DRAWING_OBJECT_H

#include "drawing/z-buffer_detachment/z-buffer_detachment.h"
#include "z-buffer/z-buffer.h"
#include "camera/base_camera.h"

typedef enum{FRAME, TEXTURE} edrawing;

class drawing_object
{
public:
    edrawing drawing;
    virtual void draw(Z_buffer_base*, const camera_base*) const = 0;
};

#endif // DRAWING_OBJECT_H
