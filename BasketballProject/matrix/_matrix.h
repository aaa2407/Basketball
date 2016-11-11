#ifndef _MATRIX_H
#define _MATRIX_H

#include "matrix_base.h"
#include "error_matrix.h"
#include "array\array.h"

template <typename type = int>
class matrix:  public matrixBase
{
public:
    matrix();
    matrix(size_t rows, size_t columns);
    matrix(size_t rows, size_t columns, const type& value);
    matrix(const matrix<type>& copy);
    matrix(matrix<type>&& copy);
    
    matrix<type>& operator=(const matrix<type>& copy);
    matrix<type>& operator=(matrix<type>&& copy);
    
    ~matrix();

    size_t rowCount() const;
    size_t columnCount() const;

    void setValue(size_t rowIndex, size_t columnIndex, const type& value);

    void setRow(size_t index, const array<type>& row);
    void setColumn(size_t index, const array<type>& column);

    void setSize(size_t rows, size_t columns);

    const type& value(size_t rowIndex, size_t columnIndex)const;

    const array<type>& row(size_t rowIndex) const;
    const array<type>& operator[](size_t rowIndex) const;
    array<type>& operator[](size_t rowIndex);

    bool isEmpty() const;
    bool operator!() const;

protected:
    void delete_matrix();    
    
protected:
    array<array<type>*> data;
};

#include "matrix.cpp"

template <typename type>
std::ostream& operator<<(std::ostream& cout, const matrix<type>& copy)
{
    cout << "matrix " << copy.rowCount() << " - " << copy.columnCount()<< std::endl;
    for (size_t i = 0; i < copy.rowCount(); i++)
    {
        cout << "{";
        for (size_t j = 0; j < copy.columnCount(); j++)
        {
            cout << " " << copy[i][j];
        }
        cout << " }" << std::endl;
    }

    return cout;
}


#endif // _MATRIX_H
