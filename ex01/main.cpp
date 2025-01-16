#include "iter.hpp"
#include "iostream"
void the_func(int &i)
{
    i = 666;
}
int main()
{
    int array[] = {22, 33, 44, 55, 66, 77, 88, 99, 111, 222};
    for (int i = 0; i < 10; i++)
        std::cout << array[i] << std::endl;
    ::iter(array, 10, the_func);
    for (int i = 0; i < 10; i++)
        std::cout << array[i] << std::endl;
    return 0;
}