#include <iostream>
#include <thread>
#include <mutex>

struct BankAccount {
    int balance = 100;
    std::mutex mtx;
};

void withdraw_money(BankAccount& account, int amount, int thread_id) {
    // RAII lock: acquires mutex now, auto-releases at end of scope
    std::lock_guard<std::mutex> lock(account.mtx);

    // --- CRITICAL SECTION ---
    std::cout << "[Thread " << thread_id << "] Attempting to withdraw $" << amount 
              << "... Current balance: $" << account.balance << "\n";

    if (account.balance >= amount) {
        account.balance -= amount;
        std::cout << "[Thread " << thread_id << "] -> SUCCESS. Remaining: $" 
                  << account.balance << "\n";
    } else {
        std::cout << "[Thread " << thread_id << "] -> FAILED. Insufficient funds.\n";
    }
}

int main() {
    BankAccount my_account;

    std::cout << "Initial balance: $" << my_account.balance << "\n\n";

    // Launch 3 threads operating on the same account
    std::thread t1(withdraw_money, std::ref(my_account), 40, 1);
    std::thread t2(withdraw_money, std::ref(my_account), 50, 2);
    std::thread t3(withdraw_money, std::ref(my_account), 30, 3);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "\nFinal balance: $" << my_account.balance << "\n";

    return 0;
}