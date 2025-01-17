#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

template<typename T>
class Array
{
private:
    T* array;
public:
    Array();
    Array(unsigned int i);
    ~Array();
};


#include "../Array.tpp"

#endif