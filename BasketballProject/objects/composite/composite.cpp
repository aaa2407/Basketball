#include "composite.h"

composite::composite(const char *name)
{
    _name = (name != NULL) ? ((char*)name) : NULL;
}
