#ifndef ERROR_POLYGON_H
#define ERROR_POLYGON_H

#include "error_polygon_base.h"

namespace errPolygon {

class errorNormal : public errorArrayBase
{
public:
    const char* what()
    {
        return "errorPolygon::insufficient number of points";
    }
};

}

#endif // ERROR_POLYGON_H
