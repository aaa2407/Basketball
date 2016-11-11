#ifndef ERROR_BASE_H
#define ERROR_BASE_H

#include <exception>

class errorBase : private std::exception
{
public:
    virtual const char* what() = 0;
};

#endif // ERROR_BASE_H
