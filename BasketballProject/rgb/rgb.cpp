#include "rgb.h"

color::rgb color::get_rgb(QColor color)
{
    color::rgb col;
    col.blue = color.blue();
    col.red = color.red();
    col.green = color.green();
    return col;
}
