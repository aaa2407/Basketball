#ifndef _MARRAY_H
#define _MARRAY_H

#include "array\array.h"
#include "error_marray.h"

template <typename type = int>
class marray
{
public:
    marray(size_t start_size = 4, size_t inc_size = 2);
    marray(const marray<type>& copy);

    marray<type>& operator=(const marray<type>& copy);

    virtual size_t size() const;

    virtual void add(type value);
    virtual void setValue(const type& value, size_t index);

    const type& operator[](size_t index) const;
    type& operator[](size_t index);

    type del(size_t index);

    void clear();

    bool operator!() const;

private:
    array<type> _arr;
    size_t _m_size;
    size_t _inc_size;
};

#include "marray.cpp"

template <typename type>
std::ostream& operator<<(std::ostream& cout, marray<type>& copy)
{
    cout << "mutable array {" << copy.size() << ": ";
    for (size_t i = 0; i < copy.size(); i++)
    {
        cout << copy[i] << " ";
    }
    cout << "}";
    return cout;
}


#endif // _MARRAY_H
