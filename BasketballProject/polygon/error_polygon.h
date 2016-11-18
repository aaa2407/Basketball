#ifndef ERROR_POLYGON_H
#define ERROR_POLYGON_H

#include "error_polygon_base.h"

namespace errPolygon {

class errorNormal : public errorPolygonBase
{
public:
    const char* what()
    {
        return "errorPolygon::insufficient number of points";
    }
};

class errorIncorrectIndex : public errorPolygonBase
{
public:
    const char* what()
    {
        return "errorPolygon::you are input an incorrect index";
    }
};

class errorPicture : public errorPolygonBase
{
public:
    const char* what()
    {
        return "errorPolygon::the picture of texture is empty";
    }
};

}

#endif // ERROR_POLYGON_H
