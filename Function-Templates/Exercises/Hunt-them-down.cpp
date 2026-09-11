#include <iostream>

template <typename T>
int hunt_down(const T& value, const T collection[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (collection[i] == value)
        {
            return static_cast<int>(i); 
        }
    }

    return -1;
}