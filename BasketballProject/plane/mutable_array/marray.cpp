#include "marray.h"

template <typename type>
marray<type>::marray(size_t start_size, size_t inc_size)
{
    _arr.setSize(start_size);
    _inc_size = inc_size;
    _m_size = 0;
}

template <typename type>
marray<type>::marray(const marray<type>& copy)
{
    _arr.setSize(copy._arr.size());
    _inc_size = copy._inc_size;
    _m_size = copy._m_size;
    for (size_t i = 0; i < _m_size; i++)
    {
        _arr[i] = copy._arr[i];
    }
}

template <typename type>
marray<type>& marray<type>::operator=(const marray<type>& copy)
{
    _arr.setSize(copy._arr.size());
    _inc_size = copy._inc_size;
    _m_size = copy._m_size;
    for (size_t i = 0; i < _m_size; i++)
    {
        _arr[i] = copy._arr[i];
    }
    return *this;
}

template <typename type>
size_t marray<type>::size() const
{
    return _m_size;
}

template <typename type>
void marray<type>::add(type value)
{
    if (_m_size == _arr.size())
    {
        _arr.setSize(_arr.size()*_inc_size);
    }
    _arr[_m_size++]= value;
}


template <typename type>
void marray<type>::setValue(const type& value, size_t index)
{
    if (index >= _m_size)
    {
       throw errMarray::errorIndex();
    }
    _arr[index] = value;
}

template <typename type>
const type& marray<type>::operator[](size_t index) const
{
    if (index >= _m_size)
    {
       throw errMarray::errorIndex();
    }
    return _arr[index];
}

template <typename type>
type& marray<type>::operator[](size_t index)
{
    if (index >= _m_size)
    {
       throw errMarray::errorIndex();
    }
    return _arr[index];
}

template <typename type>
type marray<type>::del(size_t index)
{
    if (index >= _m_size)
    {
       throw errMarray::errorIndex();
    }
    type a = _arr[index];
    for (size_t i = index; i < _m_size - 1; i++)
    {
        (*this)[i] = (*this)[i+1];
    }
    _m_size--;
    return a;
}

template <typename type>
void marray<type>::clear()
{
    _m_size = 0;
}

template <typename type>
bool marray<type>::operator!() const
{
    if (_m_size == 0)
        return true;
    else
        return false;
}
