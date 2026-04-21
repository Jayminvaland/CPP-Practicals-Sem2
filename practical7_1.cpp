#include<iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    float add(float a, float b) {
        return a + b;
    }

    double add(int a, double b) {
        return a + b;
    }

    double add(double a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    void display() {
        int i1 = 10, i2 = 20;
        float f1 = 5.5f, f2 = 4.5f;
        double d1 = 7.25, d2 = 2.75;

        cout << "Integer Addition: " << add(i1, i2) << endl;
        cout << "Float Addition: " << add(f1, f2) << endl;
        cout << "Int + Double: " << add(i1, d1) << endl;
        cout << "Double + Int: " << add(d2, i2) << endl;
        cout << "Double Addition: " << add(d1, d2) << endl;
    }
};

int main() {
    Calculator c;
    c.display();
    return 0;
}