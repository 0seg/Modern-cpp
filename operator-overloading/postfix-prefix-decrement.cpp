/*Unary Postfix and Prefix Decrement Operators*/

#include <iostream>

class Counter{
    private:
        int count;

    public:
        Counter() : count{0} {}

        Counter(int c) : count{c} {}

    Counter& operator--(){
        --count;
        return *this;
    }

    Counter operator--(int){
        Counter temp{*this};
        --(*this);
        return temp;
    }

    
    void display() const{
        std::cout << "Count: " << count << std::endl;
    }

};