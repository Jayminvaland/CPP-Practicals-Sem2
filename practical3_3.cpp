#include <iostream>
using namespace std;

class Account {
private:
    int accNo;
    string name;
    float balance;

public:
    static int totalAccounts; // static data member

    
    Account() {
        accNo = 0;
        name = "";
        balance = 0;
    }

    
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accNo;

        cout << "Enter Account Holder Name: ";
        cin >> name;

        cout << "Enter Initial Balance: ";
        cin >> balance;

        totalAccounts++;
    }

    
    void display() {
        cout << "\nAccount Number: " << accNo;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }

    
    int getAccNo() {
        return accNo;
    }

    
    void deposit(float amt) {
        balance += amt;
    }

    
    bool withdraw(float amt) {
        if (amt > balance) {
            cout << "Insufficient Balance!\n";
            return false;
        }
        balance -= amt;
        return true;
    }

    
    bool transfer(Account &receiver, float amt) {
        if (withdraw(amt)) {
            receiver.deposit(amt);
            cout << "Transfer Successful!\n";
            return true;
        }
        cout << "Transfer Failed!\n";
        return false;
    }

    
    void updateName() {
        cout << "Enter new name: ";
        cin >> name;
    }
};


int Account::totalAccounts = 0;

int main() {
    int n;
    cout << "Enter number of accounts: ";
    cin >> n;

    
    Account* acc = new Account[n];

    
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Account " << i + 1 << endl;
        acc[i].createAccount();
    }

    int choice;

    do {
        cout << "\n\n--- MENU ---";
        cout << "\n1. Display All Accounts";
        cout << "\n2. Search Account";
        cout << "\n3. Update Account Name";
        cout << "\n4. Transfer Money";
        cout << "\n5. Total Accounts";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < n; i++) {
                acc[i].display();
            }
        }

        else if (choice == 2) {
            int no, found = 0;
            cout << "Enter Account Number: ";
            cin >> no;

            for (int i = 0; i < n; i++) {
                if (acc[i].getAccNo() == no) {
                    acc[i].display();
                    found = 1;
                    break;
                }
            }
            if (!found)
                cout << "Account not found!\n";
        }

        else if (choice == 3) {
            int no;
            cout << "Enter Account Number: ";
            cin >> no;

            for (int i = 0; i < n; i++) {
                if (acc[i].getAccNo() == no) {
                    acc[i].updateName();
                    cout << "Updated Successfully!\n";
                    break;
                }
            }
        }

        else if (choice == 4) {
            int from, to;
            float amt;
            cout << "Enter Sender Account No: ";
            cin >> from;
            cout << "Enter Receiver Account No: ";
            cin >> to;
            cout << "Enter Amount: ";
            cin >> amt;

            Account *sender = NULL, *receiver = NULL;

            for (int i = 0; i < n; i++) {
                if (acc[i].getAccNo() == from)
                    sender = &acc[i];
                if (acc[i].getAccNo() == to)
                    receiver = &acc[i];
            }

            if (sender != NULL && receiver != NULL) {
                sender->transfer(*receiver, amt);
            } else {
                cout << "Invalid account number!\n";
            }
        }

        else if (choice == 5) {
            cout << "Total Accounts Created: " << Account::totalAccounts << endl;
        }

    } while (choice != 0);

    
    delete[] acc;

    return 0;
}