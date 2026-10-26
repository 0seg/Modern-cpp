/* std::queue in C++ */

#include <iostream>
#include <queue>
#include <string>

int main() {
    // A queue follows FIFO: First In, First Out.
    // Example: jobs waiting to be processed.
    std::queue<std::string> jobs;

    jobs.push("Read input");
    jobs.push("Process data");
    jobs.emplace("Write output");

    std::cout << "Jobs waiting: " << jobs.size() << '\n';
    std::cout << "Next job: " << jobs.front() << '\n';
    std::cout << "Last job in queue: " << jobs.back() << '\n';

    // Process jobs in the order they arrived.
    std::cout << "\nProcessing jobs:\n";
    while (!jobs.empty()) {
        std::cout << "Processing: " << jobs.front() << '\n';
        jobs.pop();
    }

    std::cout << "Queue empty? " << std::boolalpha << jobs.empty() << '\n';
    return 0;
}
