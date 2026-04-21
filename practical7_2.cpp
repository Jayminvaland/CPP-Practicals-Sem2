#include<iostream>
using namespace std;

class Complex {
    float real, imag;

public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    Complex operator + (Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator - (Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    void display() {
        if(imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    Complex c1(4, 5), c2(2, 3), c3, c4;

    c3 = c1 + c2;
    c4 = c1 - c2;

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "Addition Result: ";
    c3.display();

    cout << "Subtraction Result: ";
    c4.display();

    return 0;
}