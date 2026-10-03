/*Unary Postfix Increment Operator*/

#include <iostream>

class Counter
{
    private:
        int count;

    public:
        Counter() : count(0) {}

        Counter(int c) : count(c) {}

        Counter& operator++()
        {
            ++count; // Increment the count
            return *this; // Return the current object
        }

        // Overloading the unary postfix increment operator
        Counter operator++(int)
        {
            Counter temp{*this}; // Store the current state
            ++(*this); // Increment the count
            return temp; // Return the previous state
        }

        void display() const
        {
            std::cout << "Count: " << count << std::endl;
        }
};