#include <iostream>
#include <vector>
using namespace std;

class DigitalAccount {
private:
    string customerName;
    int accountID;
    double balance;

public:
   
    DigitalAccount() {
        customerName = "Default User";
        accountID = 0;
        balance = 0.0;
    }

    
    DigitalAccount(string name, int id, double initialBalance = 0.0) {
        customerName = name;
        accountID = id;

        if (initialBalance >= 0)
            balance = initialBalance;
        else {
            cout << "Invalid initial balance! Setting to 0.\n";
            balance = 0;
        }
    }

    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!\n";
        }
        else if (amount > balance) {
            cout << "Withdrawal failed! Insufficient balance.\n";
        }
        else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    
    void display() const {
        cout << "\n--- Account Summary ---\n";
        cout << "Customer Name : " << customerName << endl;
        cout << "Account ID    : " << accountID << endl;
        cout << "Balance       : " << balance << endl;
    }
};

int main() {
    vector<DigitalAccount> accounts;

    
    DigitalAccount acc1("Jaymin", 101, 5000);
    DigitalAccount acc2("Ravi", 102); // default balance = 0
    DigitalAccount acc3("Priya", 103, 2000);

    accounts.push_back(acc1);
    accounts.push_back(acc2);
    accounts.push_back(acc3);

    
    cout << "\n--- Transactions ---\n";

    accounts[0].deposit(1500);
    accounts[0].withdraw(2000);

    accounts[1].deposit(1000);
    accounts[1].withdraw(1500); 

    accounts[2].withdraw(500);
    accounts[2].deposit(-100); 

    
    cout << "\n--- Final Account Details ---\n";
    for (const auto &acc : accounts) {
        acc.display();
    }

    return 0;
}