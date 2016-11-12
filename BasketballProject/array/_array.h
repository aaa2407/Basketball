#ifndef _ARRAY_H
#define _ARRAY_H

#include "stdarg.h"
#include "array_base.h"
#include "error_array.h"
#include <iostream>

template <typename type = int>
class array:  public arrayBase
{
public:
    array();
    array(size_t size);
    array(size_t size, const type& value);
    array(const array<type>& copy);
    array(array<type>&& copy);        

    void set(size_t size, const type& value);
    void set(const array<type>& copy);
    void set(array<type>&& copy);    

    array<type>& operator=(const array<type>& copy);
    array<type>& operator=(array<type>&& copy);

    ~array();

    virtual size_t size() const;

    void setSize(size_t size);

    void setValue(size_t index, const type& value);

    const type& getValue(size_t index) const;
    const type& operator[](size_t index) const;
    type& operator[](size_t index);

    bool operator!();

protected:
    type* data;
};

#include "array.cpp"

template <typename type>
std::ostream& operator<<(std::ostream& cout, array<type>& copy)
{
    cout << "array " << "{" << copy.size() << ": ";
    for (size_t i = 0; i < copy.size(); i++)
    {
        cout << copy[i] << " ";
    }
    cout << "}";
    return cout;
}

#endif // _ARRAY_H
