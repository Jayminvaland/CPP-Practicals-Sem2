#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Loan {
private:
    int loanID;
    string name;
    double amount;
    double annualRate;
    int tenure;

public:
    Loan() {
        loanID = 0;
        name = "Default";
        amount = 0;
        annualRate = 0;
        tenure = 0;
    }

    Loan(int id, string n, double amt, double rate, int t) {
        loanID = id;
        name = n;
        amount = amt;
        annualRate = rate;
        tenure = t;
    }

    double calculateEMI() const {
        double R = annualRate / (12 * 100);
        return (amount * R * pow(1 + R, tenure)) / (pow(1 + R, tenure) - 1);
    }

    void input() {
        cout << "Enter Loan ID: ";
        cin >> loanID;
        cout << "Enter Applicant Name: ";
        cin >> name;
        cout << "Enter Loan Amount: ";
        cin >> amount;
        cout << "Enter Annual Interest Rate: ";
        cin >> annualRate;
        cout << "Enter Tenure (months): ";
        cin >> tenure;
    }

    void display() const {
        cout << "\nLoan ID: " << loanID;
        cout << "\nApplicant: " << name;
        cout << "\nLoan Amount: " << amount;
        cout << "\nAnnual Interest Rate: " << annualRate;
        cout << "\nTenure (months): " << tenure;
        cout << "\nMonthly EMI: " << calculateEMI() << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of loans: ";
    cin >> n;

    vector<Loan> loans(n);

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Loan " << i + 1 << ":\n";
        loans[i].input();
    }

    cout << "\n--- Loan Details ---\n";
    for (const auto &l : loans) {
        l.display();
    }

    return 0;
}