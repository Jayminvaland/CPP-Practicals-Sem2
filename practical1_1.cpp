#include <iostream>
using namespace std;

class Wallet {
private:
    int walletID;
    string userName;
    double balance;

public:
    
    Wallet(int id, string name, double bal = 0) {
        walletID = id;
        userName = name;
        balance = bal;
    }

    
    void loadMoney(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount loaded successfully.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }

    
    void transferMoney(Wallet &receiver, double amount) {
        if (amount <= 0) {
            cout << "Invalid transfer amount.\n";
        }
        else if (amount > balance) {
            cout << "Error: Insufficient balance!\n";
        }
        else {
            balance -= amount;
            receiver.balance += amount;
            cout << "Transfer successful.\n";
        }
    }

    
    void displayDetails() {
        cout << "\nWallet ID: " << walletID << endl;
        cout << "User Name: " << userName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    
    Wallet user1(101, "Jay");
    Wallet user2(102, "Amit");

    
    user1.loadMoney(5000);
    user2.loadMoney(2000);

   
    user1.displayDetails();
    user2.displayDetails();

   
    user1.transferMoney(user2, 1500);

    
    cout << "\nAfter Transfer:\n";
    user1.displayDetails();
    user2.displayDetails();

   
    user2.transferMoney(user1, 5000);

    return 0;
}