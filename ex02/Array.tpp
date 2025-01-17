#include <iostream>

template <typename T>
Array<T>::Array() : array(NULL) {}
template <typename T>
Array<T>::Array(unsigned int i) 
{
    array = new T[i] ();
}
template <typename T>
Array<T>::~Array()
{
    delete[] array;
}