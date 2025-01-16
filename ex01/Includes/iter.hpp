#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename SizeType>
void iter(T* array, SizeType size, void (*func)(T&))
{
    for (SizeType i = 0; i < size; ++i) {
        func(array[i]);  
    }
}

#endif