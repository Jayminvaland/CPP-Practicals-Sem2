#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

class Tracer {
    std::string funcName;
public:
    Tracer(std::string name) : funcName(name) {}
    ~Tracer() {
        std::cout << "[Stack Unwinding] Exiting function: " << funcName << std::endl;
    }
};

class BankAccount {
    double balance;
public:
    BankAccount(double initial) : balance(initial) {}

    void withdraw(double amount) {
        Tracer t("withdraw");
        if (amount > balance) {
            throw std::runtime_error("Insufficient funds! Balance: " + std::to_string(balance));
        }
        balance -= amount;
        std::cout << "Withdrawal successful. New balance: " << balance << std::endl;
    }

    void deposit(double amount) {
        Tracer t("deposit");
        if (amount <= 0) {
            throw std::runtime_error("Invalid deposit amount: " + std::to_string(amount));
        }
        balance += amount;
        std::cout << "Deposit successful. New balance: " << balance << std::endl;
    }
};

void processTransaction(BankAccount& account, int choice, double amount) {
    Tracer t("processTransaction");
    if (choice == 1) {
        account.deposit(amount);
    } else if (choice == 2) {
        account.withdraw(amount);
    }
}

int main() {
    BankAccount myAccount(500.0);
    int choice;
    double amount;

    std::cout << "--- Simple Banking System ---" << std::endl;
    std::cout << "1. Deposit\n2. Withdraw\nEnter choice: ";
    std::cin >> choice;
    std::cout << "Enter amount: ";
    std::cin >> amount;

    try {
        Tracer t("main-try-block");
        processTransaction(myAccount, choice, amount);
    } 
    catch (const std::runtime_error& e) {
        std::cout << "\nCaught Exception: " << e.what() << std::endl;
    }

    std::cout << "\nProgram execution completed." << std::endl;
    return 0;
}