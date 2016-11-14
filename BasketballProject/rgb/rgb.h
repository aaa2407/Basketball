#ifndef _RGB_H
#define _RGB_H

#include <QColor>

namespace color{

typedef struct{ // Цвет RGB
    unsigned char red;
    unsigned char blue;
    unsigned char green;
} rgb;

rgb get_rgb(QColor color);

}

#endif // RGB_H
