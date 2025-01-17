#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <cstdlib>

template<typename T>
class Array
{
private:
    T* array;
    unsigned int elements;
public:
    Array();
    Array(unsigned int i);
    Array (Array<T> const &other);
    Array<T> &operator=(Array<T> const &other);
    T& operator[](unsigned int index);
    T& operator[](int index);
    ~Array();
    class invalidIndex : public std::exception{
        const char *what() const throw();
    };

    unsigned int getElements();
    void print_array();
};


#include "../Array.tpp"

#endif