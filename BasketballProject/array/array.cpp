#include "array.h"

template <typename type>
array<type>::array()
{
    this->data = nullptr;
    this->_size = 0;
}

template <typename type>
array<type>::array(size_t size)
{
    this->data = new type[size];
    if (!this->data)
    {
        throw errArray::errorMemory();
    }
    this->_size = size;
}

template <typename type>
array<type>::array(size_t size, const type& value)
{
    this->data = new type[size];
    if (!this->data)
    {
        throw errArray::errorMemory();
    }
    for (size_t  i = 0; i < size; i++)
    {
        this->data[i] = value;
    }
    this->_size = size;
}


template <typename type>
array<type>::array(const array<type>& copy)
{
    this->data = new type[copy._size];
    if (!this->data)
    {
        throw errArray::errorMemory();
    }
    for (size_t i = 0; i < copy._size; i++)
    {
        this->data[i] = copy.data[i];
    }
    this->_size = copy._size;
}

template <typename type>
array<type>::array(array<type>&& copy)
{
    this->data = copy.data;
    copy.data = nullptr;
    this->_size = copy._size;
}

template <typename type>
void array<type>::set(size_t size, const type& value)
{
    delete [] this->data;
    this->data = new type[size];
    if (!this->data)
    {
        throw errArray::errorMemory();
    }
    for (size_t i = 0; i < size; i++)
    {
        this->data[i] = value;
    }
    this->_size = size;
}

template <typename type>
void array<type>::set(const array<type>& copy)
{
    delete [] this->data;
    type* arr = new type[copy._size];
    if (!arr)
    {
        throw errArray::errorMemory();
    }
    for (size_t i = 0; i < copy._size; i++)
    {
        this->data[i] = copy.data[i];
    }
    this->_size = copy._size;
}

template <typename type>
void array<type>::set(array<type>&& copy)
{
    delete [] this->data;
    this->data = copy.data;
    copy.data  = nullptr;
    this->_size = copy._size;
}

template <typename type>
array<type>& array<type>::operator=(const array<type>& copy)
{
    type* arr = new type[copy._size];
    if (!arr)
    {
        throw errArray::errorMemory();
    }

    delete [] this->data;
    this->data = arr;
    for (size_t i = 0; i < copy._size; i++)
    {
        this->data[i] = copy.data[i];
    }
    this->_size = copy._size;
    return *this;
}

template <typename type>
array<type>& array<type>::operator=(array<type>&& copy)
{
    delete [] this->data;
    this->data = copy.data;
    copy.data  = nullptr;
    return *this;
}

template <typename type>
array<type>::~array()
{
    setSize(0);
}

template <typename type>
size_t array<type>::size() const
{
    return this->_size;
}

template <typename type>
void array<type>::setSize(size_t size)
{
    type* newarr = new type[size];
    if (!newarr)
    {
        throw errArray::errorMemory();
    }
    size_t s = size < _size ? size : _size;
    for (size_t i = 0; i < s; i++)
    {
        newarr[i] = data[i];
    }
    delete [] data;
    data = newarr;
    _size = size;
}

template <typename type>
void array<type>::setValue(size_t index, const type& value)
{
    if (index >= this->_size)
    {
        throw errArray::errorIndex();
    }
    this->data[index] = value;
}

template <typename type>
const type& array<type>::getValue(size_t index) const
{
    if (index >= this->_size)
    {
        throw errArray::errorIndex();
    }
    return this->data[index];
}


template <typename type>
const type& array<type>::operator[](size_t index) const
{
    if (index >= this->_size)
    {
        throw errArray::errorIndex();
    }
    return this->data[index];
}

template <typename type>
type& array<type>::operator[](size_t index)
{
    if (index >= this->_size)
    {
        throw errArray::errorIndex();
    }
    return this->data[index];
}

template <typename type>
bool array<type>::operator!()
{
     return !(this->size());
}
