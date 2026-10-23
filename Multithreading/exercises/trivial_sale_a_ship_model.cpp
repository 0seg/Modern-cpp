#include <iostream>
#include <thread>
#include <cstddef>

// Forward declarations so the compiler recognizes functions before use
void cleaningCrew();
void engineCrew(std::size_t n);

int main(){
    
    std::size_t n{};

    while(true){
        // Print available commands menu
        std::cout << "\nChoose an order (1: Clean, 2: Full speed, 3: Stop, 100: Exit): ";
        std::cin >> n;

        if(n == 1){
            // Launch background cleaning thread
            std::thread clean(cleaningCrew);
            clean.detach();

        }else if(n == 2 || n == 3){
            // Launch engine thread and wait for it to finish
            std::thread engine(engineCrew, n);
            engine.join();

        }else if(n == 100){
            std::cout << "Terminate program\n";
            break;

        }else{
            std::cout << "Invalid order, enter another order\n";
        }
    }

    return 0;
}

void cleaningCrew() {
    std::cout << "Cleaning crew is cleaning the ship.\n";
}

void engineCrew(std::size_t n){
    if(n == 2) std::cout << "Full speed ahead!\n";
    if(n == 3) std::cout << "Engine stopped.\n";
}