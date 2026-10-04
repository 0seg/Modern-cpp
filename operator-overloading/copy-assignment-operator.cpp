/*copy assignment operator*/

#include <iostream>

class Counter{
    private:
        int count;

    public:
        Counter() : count{0} {}

        Counter(int c) : count{c} {}

        // Copy assignment operator
        Counter& operator=(const Counter& other){
            if(this != &other){ // self-assignment check
                count = other.count;
            }
            return *this;
        }

        void display() const{
            std::cout << "Count: " << count << std::endl;
        }

};

int main(){
    Counter c1{5};
    Counter c2;

    c2 = c1; // Using the copy assignment operator

    c1.display(); // Output: Count: 5
    c2.display(); // Output: Count: 5

    return 0;
}