#ifndef TRANSDORM_MATRIX_BASE_H
#define TRANSDORM_MATRIX_BASE_H

#include "real_matrix\real_matrix.h"

class transform_base : public rmatrix
{
public:
    transform_base() : rmatrix(4, 4)
    {
        (*this)[0][0] = 1;
        (*this)[1][1] = 1;
        (*this)[2][2] = 1;
        (*this)[3][3] = 1;
    }
};

#endif // TRANSDORM_MATRIX_BASE_H
