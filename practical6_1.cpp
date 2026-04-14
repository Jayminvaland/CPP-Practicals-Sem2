#include <iostream>
#include <vector>
using namespace std;

class Shape {
protected:
    float radius;

public:
   
    void setRadius(float r) {
        radius = r;
    }

   
    float getRadius() {
        return radius;
    }
};


class Circle : public Shape {
public:
   
    float calculateArea() {
        return 3.14159 * radius * radius;
    }
};

int main() {
    int n;

    cout << "Enter number of circles: ";
    cin >> n;

    
    vector<Circle> dynamicCircles(n);

    cout << "\nEnter radii for dynamic circles:\n";
    for (int i = 0; i < n; i++) {
        float r;
        cout << "Radius " << i + 1 << ": ";
        cin >> r;
        dynamicCircles[i].setRadius(r);
    }

    cout << "\nAreas (Dynamic Method):\n";
    for (int i = 0; i < n; i++) {
        cout << "Circle " << i + 1 << " Area: "
             << dynamicCircles[i].calculateArea() << endl;
    }

    
    Circle staticCircles[100]; // fixed size

    cout << "\nEnter radii for static circles:\n";
    for (int i = 0; i < n; i++) {
        float r;
        cout << "Radius " << i + 1 << ": ";
        cin >> r;
        staticCircles[i].setRadius(r);
    }

    cout << "\nAreas (Static Method):\n";
    for (int i = 0; i < n; i++) {
        cout << "Circle " << i + 1 << " Area: "
             << staticCircles[i].calculateArea() << endl;
    }

    return 0;
}