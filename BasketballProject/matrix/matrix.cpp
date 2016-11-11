#include "matrix.h"


template <typename type>
matrix<type>::matrix()
{
    _rowCount = 0;
    _columnCount = 0;
}


template <typename type>
matrix<type>::matrix(size_t rows, size_t columns)
{
    _rowCount = rows;
    _columnCount = columns;
    data.setSize(rows);
    for (uint i = 0; i < rows; i++)
    {
        array<type> *newarr = new array<type>();
        newarr->setSize(columns);
        if (!newarr)
        {
            this->delete_matrix();
            throw errMatrix::errorMemory();
        }
        data[i] = newarr;
    }
}

template <typename type>
matrix<type>::matrix(size_t rows, size_t columns, const type& value)
{   
    _rowCount = rows;
    _columnCount = columns;
    data.setSize(rows);
    for (uint i = 0; i < rows; i++)
    {
        array<type> *newarr = new array<type>(columns, value);
        if (!newarr)
        {
            this->delete_matrix();
            throw errMatrix::errorMemory();
        }
        data[i] = newarr;
    }
}

template <typename type>
matrix<type>::matrix(const matrix<type>& copy)
{
    _rowCount = copy._rowCount;
    _columnCount = copy._columnCount;
    data.setSize(_rowCount);
    for (uint i = 0; i < _rowCount; i++)
    {
        array<type> *newarr = new array<type>(copy[i]);
        if (!newarr)
        {
            this->delete_matrix();
            throw errMatrix::errorMemory();
        }
        data[i] = newarr;
    }
}

template <typename type>
matrix<type>::matrix(matrix<type>&& copy)
{
    this->data = copy.data;
    copy.data.setSize(0);   
}


template <typename type>
matrix<type>& matrix<type>::operator=(const matrix<type>& copy)
{
    this->delete_matrix();
    matrix<type>::matrix(copy);
    return *this;
}

template <typename type>
matrix<type>& matrix<type>::operator=(matrix<type>&& copy)
{
    this->delete_matrix();
    matrix<type>::matrix(copy);
    return *this;
}

template <typename type>
matrix<type>::~matrix()
{
    this->delete_matrix();
}

template <typename type>
uint matrix<type>::rowCount() const
{
    return _rowCount;
}

template <typename type>
uint matrix<type>::columnCount() const
{
    return _columnCount;
}


template <typename type>
void matrix<type>::setValue(size_t rowIndex, size_t columnIndex, const type& value)
{
    if (rowIndex >= _rowCount || columnIndex >= _columnCount)
    {
        throw errMatrix::errorIndex();
    }
    data[rowIndex][columnIndex] = value;
}

template <typename type>
void matrix<type>::setRow(size_t index, const array<type>& row)
{
    if (_columnCount != row.size())
    {
        throw errMatrix::errorSetRow();
    }
    if (index >= _rowCount)
    {
        throw errMatrix::errorIndex();
    }
    (*this)[index] = row;
}

template <typename type>
void matrix<type>::setColumn(size_t index, const array<type>& column)
{
    if (_rowCount != column.size())
    {
        throw errMatrix::errorSetColumn();
    }
    if (index >= _columnCount)
    {
        throw errMatrix::errorIndex();
    }
    for (size_t i = 0; i < _rowCount; i++)
    {
       (*this)[i][index] = column[i];
    }
}

template <typename type>
const type& matrix<type>::value(size_t rowIndex, size_t columnIndex) const
{
    if (rowIndex >= _rowCount || columnIndex >= _columnCount)
    {
        throw errMatrix::errorIndex();
    }
    return (*this)[rowIndex][columnIndex];
}


template <typename type>
const array<type>& matrix<type>::row(size_t rowIndex) const
{
    if (rowIndex >= _rowCount)
    {
        throw errMatrix::errorIndex();
    }
    return (*data[rowIndex]);
}

template <typename type>
const array<type>& matrix<type>::operator[](size_t rowIndex) const
{
    return row(rowIndex);
}

template <typename type>
array<type>& matrix<type>::operator[](size_t rowIndex)
{
    if (rowIndex >= _rowCount)
    {
        throw errMatrix::errorIndex();
    }
    return *(data[rowIndex]);
}


template <typename type>
bool matrix<type>::isEmpty() const
{
   return (!_rowCount || !_columnCount || !data);
}

template <typename type>
bool matrix<type>::operator!() const
{
    return isEmpty();
}


template <typename type>
void matrix<type>::delete_matrix()
{
    for (size_t i = 0; i < _rowCount; i++)
    {
        array<type>* arr = this->data[i];
        delete arr;
    }
    this->data.setSize(0);
    _rowCount = 0;
    _columnCount = 0;
}
