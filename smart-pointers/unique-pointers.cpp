/* Unique Pointers in C++ */

#include <iostream>
#include <memory> // for std::unique_ptr

class Operations{

    public:
        Operations(int x, int y): a(x), b(y) {}

        int add(){
            return a + b;
        }

        int subtract(){
            return a - b;
        }

        int multiply(){
            return a * b;
        }

        
    private:
        int a;
        int b;
};

int main(){
    std::unique_ptr<Operations> op1 = std::make_unique<Operations>(10, 5);

    std::cout << "Addition: " << op1->add() << std::endl;

    std::cout << "Subtraction: " << op1->subtract() << std::endl;

    std::cout << "Multiplication: " << op1->multiply() << std::endl;

    std::cout << "Address of op1: " << op1.get() << std::endl;

    std::unique_ptr<Operations> op2 = std::move(op1); // Transfer ownership to op2

    std::cout << "Address of op2: " << op2.get() << std::endl;
    
    std::cout << "Address of op1 after move: " << op1.get() << std::endl; // op1 is now nullptr

    op2.reset(); // Destroy the managed object and release ownership
    
    std::cout << "Address of op2 after reset: " << op2.get() << std::endl; // op2 is now nullptr   

    


    return 0;
}