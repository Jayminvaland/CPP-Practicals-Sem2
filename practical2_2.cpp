#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float m1, m2, m3;

public:
    
    Student() {
        rollNo = 0;
        name = "Test";
        m1 = m2 = m3 = 0;
    }

    
    Student(int r, string n, float a, float b, float c) {
        rollNo = r;
        name = n;
        m1 = a;
        m2 = b;
        m3 = c;
    }

   
    void input() {
        cout << "Enter Roll No: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter marks of 3 subjects: ";
        cin >> m1 >> m2 >> m3;
    }

    
    float getAverage() {
        return (m1 + m2 + m3) / 3;
    }

    
    void display() {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << m1 << ", " << m2 << ", " << m3;
        cout << "\nAverage: " << getAverage() << endl;
    }
};

int main() {
    Student s[100];
    int n, choice;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\n1. Default values\n2. User input\nChoose: ";
        cin >> choice;

        if (choice == 1) {
            s[i] = Student(); // default constructor
        } else {
            int r;
            string name;
            float a, b, c;

            cout << "Enter Roll No: ";
            cin >> r;
            cout << "\nEnter Name: ";
            cin >> name;
            cout << "\nEnter marks: ";
            cin >> a >> b >> c;

            s[i] = Student(r, name, a, b, c); // parameterized constructor
        }
    }

   
    cout << "\n--- Student Records ---\n";
    for (int i = 0; i < n; i++) {
        s[i].display();
    }

    return 0;
}