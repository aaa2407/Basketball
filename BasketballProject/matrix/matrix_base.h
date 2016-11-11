#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H

#include <cstddef>

class matrixBase
{
public:
    virtual size_t rowCount() const = 0;
    virtual size_t columnCount() const = 0;

protected:
    size_t _rowCount;
    size_t _columnCount;
};

#endif // MATRIX_BASE_H
