#include <iostream>
#include <thread>

// Forward declarations so the compiler recognizes functions before use
void functionA();
void functionB();
void test();

int main() {
    // 1. Launch thread A
    std::thread A(functionA);

    // Wait for thread A (and its nested thread C) to finish first
    A.join(); 

    // 2. Launch thread B after thread A finishes
    std::thread B(functionB);

    // Wait for thread B to finish
    B.join();

    // Main thread finishes last
    return 0;
}

void functionA() {
    std::cout << "Hello from -> funcA()" << "\n";

    // Launch nested thread C to run test()
    std::thread C(test);

    // Wait for thread C to complete before functionA finishes
    // Order: Thread C finishes 1st -> Thread A finishes 2nd
    C.join(); 
}

void functionB() {
    std::cout << "Hello from -> funcB()" << "\n";
}

void test() {
    std::cout << "Hello from -> test()" << "\n"; 
}