/*std::thread in C++*/

#include <iostream>
#include <thread>

void threadFunction(int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "Thread Function: " << i << std::endl;
    }
}

int main() {
    int n = 5;

    // Create a thread that runs the threadFunction
    std::thread t(threadFunction, n);

    // Wait for the thread to finish
    t.join();

    std::cout << "Main thread finished." << std::endl;

    return 0;
}
