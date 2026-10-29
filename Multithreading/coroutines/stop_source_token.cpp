
#include <chrono>
#include <iostream>
#include <stop_token>
#include <thread>

void worker(std::stop_token token) {
    int task = 1;

    while (!token.stop_requested()) {
        std::cout << "Processing task " << task++ << '\n';

        std::this_thread::sleep_for(
            std::chrono::milliseconds(500)
        );
    }

    std::cout << "Worker stopped.\n";
}

int main() {
    std::stop_source source;
    std::stop_token token = source.get_token();

    std::jthread t(worker, token);

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Requesting stop...\n";
    source.request_stop();

    t.join();

    std::cout << "Main finished.\n";
    return 0;
}
