#ifndef ERROR_PLANE_H
#define ERROR_PLANE_H

#include "error_plane_base.h"

namespace errPlane {

class errorPlane : public errorPlaneBase
{
public:
   const char* what()
   {
       return "errorPlane::the plane is incorrected";
   }
};

}

#endif // ERROR_PLANE_H
