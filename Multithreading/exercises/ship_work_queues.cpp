#include <iostream>
#include <thread>
#include <queue>
#include <chrono>

// Function declarations with clear and descriptive names
void cleaningWorker(std::queue<int>& q, bool& done);
void engineWorker(std::queue<int>& q, bool& done);

int main() {
    // Flag to stop the threads gracefully
    bool done{false};

    // Queues for tasks
    std::queue<int> cleaner{};
    std::queue<int> engine{};

    // Variable for user input
    std::size_t n{};

    // Start worker threads and pass queues and flag by reference
    std::thread t1(cleaningWorker, std::ref(cleaner), std::ref(done));
    std::thread t2(engineWorker, std::ref(engine), std::ref(done));

    // Main loop (Producer)
    while (true) {
        std::cout << "Enter command (1: Clean, 2-3: Engine, 100: Exit): ";
        std::cin >> n;
        
        // Push tasks to the correct queue
        if (n == 1) {
            cleaner.push(n);
        } else if (n == 2 || n == 3) {
            engine.push(n);
        } else if (n == 100) {
            // Signal threads to stop and exit loop
            done = true;
            break;
        } else {
            std::cout << "Invalid order\n";
        }
    }

    // Wait for threads to finish before closing the program
    t1.join();
    t2.join();

    return 0;
}

// Cleaning worker thread function (Consumer)
void cleaningWorker(std::queue<int>& q, bool& done) {
    while (!done) {
        // Check if there is work in the queue
        if (!q.empty()) {
            int command = q.front();
            q.pop();

            // Simulate work time
            std::this_thread::sleep_for(std::chrono::seconds(1));
            
            std::cout << "Cleaning crew is cleaning the ship.\n";
        } else {
            // Sleep longer if queue is empty to save CPU
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
}

// Engine worker thread function (Consumer)
void engineWorker(std::queue<int>& q, bool& done) {
    while (!done) {
        // Check if there is work in the queue
        if (!q.empty()) {
            int command = q.front();
            q.pop();

            // Process command
            if (command == 2) {
                std::cout << "max velocity\n";
            }
            if (command == 3) {
                std::cout << "stop engine\n"; 
            }

            // Simulate work time
            std::this_thread::sleep_for(std::chrono::seconds(1));
        } else {
            // Sleep longer if queue is empty to save CPU
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
}