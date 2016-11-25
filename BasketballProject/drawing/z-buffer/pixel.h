#ifndef PIXEL_H
#define PIXEL_H

#include "rgb/rgb.h"

struct pixel
{
public:
    size_t depth;       // Глубина пикселя
    color::rgb    color;
};

#endif // PIXEL_H
