#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    float basicSalary;
    float bonus;

public:
    // ✅ Default constructor (fixes your error)
    Employee() {
        name = "";
        basicSalary = 0;
        bonus = 0;
    }

    // Parameterized constructor with default bonus
    Employee(string n, float bs, float b = 2000) {
        name = n;
        basicSalary = bs;
        bonus = b;
    }

    // Inline function to calculate total salary
    inline float calculateTotalSalary() {
        return basicSalary + bonus;
    }

    // Function to input employee details
    void input() {
        char choice;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Basic Salary: ";
        cin >> basicSalary;

        cout << "Do you want to enter custom bonus? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Enter Bonus: ";
            cin >> bonus;
        } else {
            bonus = 2000; // default bonus
        }
    }

    // Function to display details
    void display() {
        cout << "\nEmployee Name: " << name;
        cout << "\nBasic Salary: " << basicSalary;
        cout << "\nBonus: " << bonus;
        cout << "\nTotal Salary: " << calculateTotalSalary() << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    // ✅ Now this works because default constructor exists
    Employee* emp = new Employee[n];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Employee " << i + 1 << endl;
        emp[i].input();
    }

    // Output
    cout << "\n--- Employee Details ---\n";
    for (int i = 0; i < n; i++) {
        emp[i].display();
    }

    // Free memory
    delete[] emp;

    return 0;
}