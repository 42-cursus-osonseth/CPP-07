#include <iostream>
#include <exception>

template <typename T>
const char *Array<T>::invalidIndex::what() const throw(){
    return ("Invalid Index");
}

template <typename T>
Array<T>::Array() : array(NULL) {}
template <typename T>
Array<T>::Array(unsigned int i) : elements(i)
{
    array = new T[i]();
    for (unsigned int i = 0; i < elements; i++)
        array[i] = i;
}
template <typename T>
Array<T>::~Array()
{
    delete[] array;
}
template <typename T>
Array<T>::Array(Array<T> const &other) : elements(other.elements)
{
    array = new T[elements]();
    for (unsigned int i = 0; i < elements; i++)
        array[i] = other.array[i];
}
template <typename T>
unsigned int Array<T>::getElements() { return elements; }

template <typename T>
void Array<T>::print_array()
{
    for (unsigned int i = 0; i < elements; i++)
        std::cout << array[i] << std::endl;
}
template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &other)
{
    if (this != other)
    {
        delete[] array;
        elements = other.elements;
        array = new T[elements]();
        for (unsigned int i = 0; i < elements; i++)
            array[i] = other.array[i];
    }
    return *this;
}
//----------------------------------------------------
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index > elements - 1)
        throw Array<T>::invalidIndex();
    return array[index];
}
template <typename T>
T &Array<T>::operator[](int index)
{
    if (index < 0 || index > static_cast<int>(elements - 1))
       throw Array<T>::invalidIndex();
    return array[index];
}

