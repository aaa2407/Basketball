#ifndef WARNING_BASE_H
#define WARNING_BASE_H

#include <exception>

class warningBase : private std::exception
{
public:
    virtual const char* what() = 0;
};

#endif // WARNING_BASE_H
