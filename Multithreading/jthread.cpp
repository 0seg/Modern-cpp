
#include <chrono>
#include <iostream>
#include <thread>

void worker(std::stop_token stop) {
    int task = 1;

    while (!stop.stop_requested()) {
        std::cout << "Processing task " << task++ << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "Worker stopped.\n";
}

int main() {
    std::jthread t(worker);

    std::this_thread::sleep_for(std::chrono::seconds(2));

    t.request_stop();

    std::cout << "Stop requested.\n";
}
