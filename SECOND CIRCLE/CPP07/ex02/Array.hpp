#pragma once

/*
Requirements:
1. Use operator new[] to allocate memory. Preventive allocation is forbidden.
2. Program must never access non-allocated memory.
3. Elements must be accessible through subscript operator [].
4. When accessing elements with [], throw std::exception if index is out of bounds.
5. Implement size() member function that:
    - Returns number of elements in array
    - Takes no parameters
    - Must not modify current instance
*/

#include <iostream>

template <typename T>
class Array
{
    private:
        T*              n_array;
        unsigned int    n_size;

    public:
        Array();
        Array(unsigned int n);
        ~Array();
        Array<T> & operator=(Array<T> const & rhs);
        Array(Array<T> const & oth);
        T& operator[](unsigned int index);
        unsigned int size() const;
};

#include "Array.tpp"