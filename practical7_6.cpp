#include<iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base Constructor\n";
    }

    
    ~Base() {
        cout << "Base Destructor\n";
    }
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() {
        cout << "Derived Constructor\n";
        data = new int[5];  
    }
~Derived() {
    cout << "Derived Destructor\n";
    delete[] data;
}
};

int main() {
    Base* ptr = new Derived();  
    delete ptr;  
    return 0;
}