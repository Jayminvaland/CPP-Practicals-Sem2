#include<iostream>
#include<queue>
using namespace std;

class Fahrenheit;

class Celsius {
    float temp;
public:
    Celsius(float t = 0) {
        temp = t;
    }

    float getTemp() {
        return temp;
    }

    operator Fahrenheit();

    bool operator == (Celsius c) {
        return temp == c.temp;
    }
};

class Fahrenheit {
    float temp;
public:
    Fahrenheit(float t = 0) {
        temp = t;
    }

    float getTemp() {
        return temp;
    }

    operator Celsius() {
        float c = (temp - 32) * 5 / 9;
        return Celsius(c);
    }

    bool operator == (Fahrenheit f) {
        return temp == f.temp;
    }
};

Celsius::operator Fahrenheit() {
    float f = (temp * 9 / 5) + 32;
    return Fahrenheit(f);
}

int main() {
    Celsius c1(25), c2(100);
    Fahrenheit f1, f2;

    f1 = c1;
    f2 = c2;

    cout << "Celsius to Fahrenheit:" << endl;
    cout << c1.getTemp() << " C = " << f1.getTemp() << " F" << endl;
    cout << c2.getTemp() << " C = " << f2.getTemp() << " F" << endl;

    Celsius c3;
    c3 = f1;

    cout << "Fahrenheit to Celsius:" << endl;
    cout << f1.getTemp() << " F = " << c3.getTemp() << " C" << endl;

    if(c1 == c2)
        cout << "Celsius temperatures are equal" << endl;
    else
        cout << "Celsius temperatures are not equal" << endl;

    if(f1 == f2)
        cout << "Fahrenheit temperatures are equal" << endl;
    else
        cout << "Fahrenheit temperatures are not equal" << endl;

    queue<Celsius> q;
    q.push(c1);
    q.push(c2);
    q.push(c3);

    cout << "Queue (Celsius values):" << endl;
    while(!q.empty()) {
        cout << q.front().getTemp() << " C" << endl;
        q.pop();
    }

    Fahrenheit arr[3];
    arr[0] = f1;
    arr[1] = f2;
    arr[2] = c3;

    cout << "Array (Fahrenheit values):" << endl;
    for(int i = 0; i < 3; i++) {
        cout << arr[i].getTemp() << " F" << endl;
    }

    return 0;
}