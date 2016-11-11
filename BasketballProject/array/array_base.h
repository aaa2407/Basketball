#ifndef ARRAY_BASE_H
#define ARRAY_BASE_H

#include <cstring>

class arrayBase
{
public:
    virtual size_t size() const = 0;

protected:
    size_t _size;
};

#endif // ARRAY_BASE_H
