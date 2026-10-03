/*Unary Prefix Increment Operator*/

#include <iostream>

class Counter
{
    private:
        int count;

    public:
        Counter() : count(0) {}

        Counter(int c) : count(c) {}

        // Overloading the unary prefix increment operator
        Counter& operator++()
        {
            ++count; // Increment the count
            return *this; // Return the current object
        }

        void display() const
        {
            std::cout << "Count: " << count << std::endl;
        }
};

int main()
{
    Counter c{5}; // Initialize count to 5


    std::cout << "Initial value of count:" << std::endl;
    c.display();

    ++c; // Using the overloaded unary prefix increment operator
    std::cout << "\nAfter prefix increment:" << std::endl;
    c.display();

    return 0;
}