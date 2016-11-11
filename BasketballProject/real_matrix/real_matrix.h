#ifndef RMATRIX_H
#define RMATRIX_H

#include "error_rmatrix.h"
#include "matrix\matrix.h"
#include "array\array.h"

class rmatrix : public matrix<double>
{
public:
    rmatrix();
    rmatrix(size_t rowCount, size_t columnCount);
    rmatrix(size_t rowCount, size_t columnCount, double value);
    rmatrix(const rmatrix& copy);
    rmatrix(rmatrix&& copy);

    rmatrix& operator=(const rmatrix& copy);
    rmatrix& operator=(rmatrix&& copy);

    rmatrix transposition() const;

    void multiplaction(double value);
    rmatrix operator*(double value) const;
    rmatrix& operator*=(double value);

    void division(double value);
    rmatrix operator/(double value) const;
    rmatrix& operator/=(double value);

    void addition(const rmatrix &right);
    rmatrix operator+(const rmatrix& right) const;
    rmatrix& operator+=(const rmatrix& right);

    void subtraction(const rmatrix& right);
    rmatrix operator-(const rmatrix& right) const;
    rmatrix& operator-=(const rmatrix& right);

    rmatrix multiplaction(const rmatrix& right) const;
    rmatrix multiplaction(const array<double>& right) const;
    rmatrix operator*(const rmatrix& right) const;
    rmatrix operator*(const array<double>& right) const;
    rmatrix& operator*=(const rmatrix& right);
    rmatrix& operator*=(const array<double>& right);

    void negation();
    rmatrix operator-() const;
};

rmatrix operator*(double left, const rmatrix& right);
array<double> operator*(const array<double>& left, const rmatrix& right);


#endif // RMATRIX_H
