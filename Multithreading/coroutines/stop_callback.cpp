
#include <iostream>
#include <stop_token>
#include <thread>

int main() {
    std::jthread worker([](std::stop_token token) {
        std::stop_callback callback(token, [] {
            std::cout << "Stop requested!\n";
        });

        while (!token.stop_requested()) {
            std::this_thread::yield();
        }

        std::cout << "Worker finished.\n";
    });

    worker.request_stop();

    return 0;
}
