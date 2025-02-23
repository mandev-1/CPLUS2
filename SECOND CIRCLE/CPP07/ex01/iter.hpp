#pragma once

#include <iostream>

template<typename T, typename Func>
void iter(T *array, size_t length, Func f)
{
    for (size_t i = 0; i < length; ++i)
    {
        f(array[i]);
    }
}

template<typename T>
void printElement(const T &elem)
{
    std::cout << elem << " " << std::endl;
}
