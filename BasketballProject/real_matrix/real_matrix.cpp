#include "real_matrix.h"

rmatrix::rmatrix()
{ }

rmatrix::rmatrix(size_t rowCount, size_t columnCount)
        : matrix<double>(rowCount, columnCount, 0)
{ }

rmatrix::rmatrix(size_t rowCount, size_t columnCount, double value)
        : matrix<double>(rowCount, columnCount, value)
{ }

rmatrix::rmatrix(const rmatrix& copy) : matrix<double>(copy)
{ }

rmatrix::rmatrix(rmatrix&& copy): matrix<double>(copy)
{}

rmatrix& rmatrix::operator=(const rmatrix& copy)
{
    this->delete_matrix();
    _rowCount = copy._rowCount;
    _columnCount = copy._columnCount;
    this->data.setSize(copy.rowCount());
    for (size_t i = 0; i < _rowCount; i++)
    {
        array<double>* newarr = new array<double>(copy[i]);
        this->data[i] = newarr;
    }
    return *this;
}

rmatrix& rmatrix::operator=(rmatrix&& copy)
{
    this->delete_matrix();
    _rowCount = copy._rowCount;
    _columnCount = copy._columnCount;
    this->data.setSize(copy.rowCount());
    for (size_t i = 0; i < _rowCount; i++)
    {
        array<double>* newarr = copy.data[i];
        this->data[i] = newarr;
        copy.data[i] = NULL;
    }
    return *this;
}

rmatrix rmatrix::transposition() const
{
    rmatrix transp(_columnCount, _rowCount);
    for (size_t i = 0; i < _rowCount; i++)
    {
        for (size_t j = 0; j < _columnCount; j++)
        {
            transp[j][i] = this->value(i, j);
        }
    }
    return transp;
}

void rmatrix::multiplaction(double value)
{
    for (size_t i = 0; i < _rowCount; i++)
    {
        for (size_t j = 0; j < _columnCount; j++)
        {
            (*this)[i][j] *= value;
        }
    }
}

rmatrix rmatrix::operator*(double value) const
{
    rmatrix matr(*this);
    matr.multiplaction(value);
    return matr;
}

rmatrix& rmatrix::operator*=(double value)
{
    this->multiplaction(value);
    return *this;
}

void rmatrix::division(double value)
{
    if (!value)
    {
        throw errRMatrix::errorDivisionZero();
    }
    this->multiplaction(1/value);
}

rmatrix rmatrix::operator/(double value) const
{
    if (!value)
    {
        throw errRMatrix::errorDivisionZero();
    }
    return (*this)*(1/value);
}

rmatrix& rmatrix::operator/=(double value)
{
    this->division(value);
    return *this;
}

void rmatrix::addition(const rmatrix& right)
{
    if (_rowCount != right._rowCount || _columnCount != right._columnCount)
    {
        throw errRMatrix::errorAddition();
    }
    for (size_t i = 0; i < _rowCount; i++)
    {
        for (size_t j = 0; j < _columnCount; j++)
        {
            (*this)[i][j] += right[i][j];
        }
    }
}

rmatrix rmatrix::operator+(const rmatrix& right) const
{
    rmatrix matr(*this);
    matr.addition(right);
    return matr;
}

rmatrix& rmatrix::operator+=(const rmatrix& right)
{
    this->addition(right);
    return *this;
}

void rmatrix::subtraction(const rmatrix& right)
{
    this->addition(-right);
}

rmatrix rmatrix::operator-(const rmatrix& right) const
{
    return (*this)+(-right);
}

rmatrix& rmatrix::operator-=(const rmatrix& right)
{
    this->subtraction(right);
    return *this;
}

rmatrix rmatrix::multiplaction(const rmatrix& right) const
{
    if (_columnCount != right._rowCount)
    {
        errRMatrix::errorMultiplation();
    }
    rmatrix matr(this->_rowCount, right._columnCount);
    for (size_t i = 0; i < matr._rowCount; i++)
        for (size_t j = 0; j < matr._columnCount; j++)
        {
            matr[i][j] = 0;
            for (size_t k = 0; k < this->_columnCount; k++)
            {
                matr[i][j] += (*this)[i][k] * right[k][j];
            }
            if (matr[i][j] < 1e-6 && matr[i][j] > -1e-6)
                matr[i][j] = 0;
        }
    return matr;
}

rmatrix rmatrix::multiplaction(const array<double>& right) const
{
    if (_columnCount != 1)
    {
        errRMatrix::errorMultiplation();
    }
    rmatrix matr(_rowCount, right.size());
    for (size_t i = 0; i < matr._rowCount; i++)
        for (size_t j = 0; j < matr._columnCount; j++)
        {
            matr[i][j] = (*this)[i][0] * right[j];
        }
    return matr;
}

rmatrix rmatrix::operator*(const rmatrix& right) const
{
    return multiplaction(right);
}

rmatrix rmatrix::operator*(const array<double>& right) const
{
    return multiplaction(right);
}

rmatrix& rmatrix::operator*=(const rmatrix& right)
{
    (*this) = (*this).multiplaction(right);
    return *this;
}

rmatrix& rmatrix::operator*=(const array<double>& right)
{
    (*this) = (*this).multiplaction(right);
    return *this;
}

void rmatrix::negation()
{
    for (size_t i = 0; i < _rowCount; i++)
        for (size_t j = 0; j < _columnCount; j++)
        {
            (*this)[i][j] = -(*this)[i][j];
        }
}


rmatrix rmatrix::operator-() const
{
    rmatrix matr(*this);
    matr.negation();
    return matr;
}

rmatrix operator*(double left, const rmatrix& right)
{
    rmatrix newm(right);
    return newm * left;
}

array<double> operator*(const array<double>& left, const rmatrix& right)
{
    if (left.size() != right.rowCount())
    {
        throw errRMatrix::errorMultiplation();
    }
    array<double> arr(right.columnCount(), 0);
    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = 0; j < left.size(); j++)
        {
            arr[i] += left[j] * right[j][i];
        }
    }
    return arr;
}
