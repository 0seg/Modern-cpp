/**
 * new-fails.cpp
 */

#include <iostream>
#include <new>

int main()
{
    // Attempting to allocate an extremely large array

    int* data = new int[10000000000000000000];

    // This will likely fail and throw a std::bad_alloc exception
    // due to insufficient memory.


    // Attempting multiple large memory allocations

    for (size_t i = 0; i < 100000000000000; ++i)
    {
        int* ptr = new int[10000000000000];
    }

    // This will also likely fail and throw a std::bad_alloc exception
    // due to insufficient memory.


    // Use exception handling to catch std::bad_alloc and handle
    // allocation failures gracefully.

    for (size_t i = 0; i < 100000000000000; ++i)
    {
        try
        {
            int* ptr = new int[10000000000000];
        }
        catch (const std::exception& ex)
        {
            std::cerr << "Memory allocation failed: "
                      << ex.what() << '\n';
        }
    }


    // std::nothrow prevents exceptions from being thrown on allocation
    // failure and returns nullptr instead.

    for (size_t i = 0; i < 100000000000000; ++i)
    {
        int* ptr = new (std::nothrow) int[10000000000000];

        if (ptr == nullptr)
        {
            std::cerr << "Memory allocation failed: returned nullptr\n";
        }
    }

    return 0;
}