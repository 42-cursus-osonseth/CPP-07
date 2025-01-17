#include <iostream>
#include <Array.hpp>
#include <ctime>

#define MAX_VAL 750
int main(int, char**)
{
    Array<char> numbers(MAX_VAL);
    char* mirror = new char[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const char value = 32 + (rand() % 95);
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<char> tmp = numbers;
        Array<char> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = 32 + (rand() % 95);
    }
    numbers.print_array();
    delete [] mirror;
    return 0;
}