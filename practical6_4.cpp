#include<iostream>
#include<vector>
using namespace std;

class Account {
protected:
    int accNo;
    double balance;
    vector<double> history;
public:
    Account(int a, double b) {
        accNo = a;
        balance = b;
    }
    virtual ~Account() {}
    virtual void deposit(double amt) {
        balance += amt;
        history.push_back(amt);
    }
    virtual void withdraw(double amt) {
        balance -= amt;
        history.push_back(-amt);
    }
    void undo() {
        if (!history.empty()) {
            balance -= history.back();
            history.pop_back();
        }
    }
    virtual void display() {
        cout << "Account No: " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }
    void showHistory() {
        cout << "Transaction History:" << endl;
        for (double t : history)
            cout << t << endl;
    }
};

class SavingsAccount : public Account {
    double interestRate;
public:
    SavingsAccount(int a, double b, double r) : Account(a, b) {
        interestRate = r;
    }
    void addInterest() {
        double interest = balance * interestRate / 100;
        deposit(interest);
    }
    void display() override {
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CurrentAccount : public Account {
    double overdraftLimit;
public:
    CurrentAccount(int a, double b, double l) : Account(a, b) {
        overdraftLimit = l;
    }
    void withdraw(double amt) override {
        if (balance - amt >= -overdraftLimit) {
            balance -= amt;
            history.push_back(-amt);
        } else {
            cout << "Overdraft limit exceeded" << endl;
        }
    }
    void display() override {
        Account::display();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    SavingsAccount sa(101, 5000, 5);
    CurrentAccount ca(102, 2000, 1000);

    sa.deposit(2000);
    sa.withdraw(500);
    sa.addInterest();
    sa.display();
    sa.showHistory();
    sa.undo();
    cout << "After Undo:" << endl;
    sa.display();
    cout << endl;
    ca.deposit(2000);
    ca.withdraw(2500);
    ca.display();
    ca.showHistory();
    ca.undo();
    cout << "After Undo:" << endl;
    ca.display();
    return 0;
}