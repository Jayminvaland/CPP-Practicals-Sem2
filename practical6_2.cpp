#include<iostream>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : public Person {
protected:
    int empID;
public:
    Employee(string n, int a, int id) : Person(n, a) {
        empID = id;
    }
    int getID() {
        return empID;
    }
    void displayEmployee() {
        displayPerson();
        cout << "Employee ID: " << empID << endl;
    }
};

class Manager : public Employee {
    string department;
public:
    Manager(string n, int a, int id, string dept) : Employee(n, a, id) {
        department = dept;
    }
    void displayManager() {
        displayEmployee();
        cout << "Department: " << department << endl;
    }
};

Manager* findManagerByID(vector<Manager*> &list, int id) {
    for (auto m : list) {
        if (m->getID() == id)
            return m;
    }
    return NULL;
}

int main() {
    vector<Manager*> managers;

    managers.push_back(new Manager("Harsh", 40, 101, "HOD"));
    managers.push_back(new Manager("Dhruv", 45, 102, "Finance"));
    managers.push_back(new Manager("Raj", 50, 103, "IT"));

    cout << "All Managers:" << endl;
    for (auto m : managers) {
        m->displayManager();
        cout << endl;
    }

    int searchID = 102;
    Manager* result = findManagerByID(managers, searchID);

    if (result) {
        cout << "Manager Found:" << endl;
        result->displayManager();
    } else {
        cout << "Manager not found" << endl;
    }

    Manager staticManagers[2] = {
        Manager("David", 38, 201, "Sales"),
        Manager("Adam", 42, 202, "Marketing")
    };

    cout << endl << "Static Managers:" << endl;
    for (int i = 0; i < 2; i++) {
        staticManagers[i].displayManager();
        cout << endl;
    }

    for (auto m : managers) {
        delete m;
    }

    return 0;
}