#include<iostream>
#include<vector>
using namespace std;

class Shape {
public:
    virtual float Area() = 0;
};

class Rectangle : public Shape {
    float length, width;
public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    float Area() {
        return length * width;
    }
};

class Circle : public Shape {
    float radius;
public:
    Circle(float r) {
        radius = r;
    }

    float Area() {
        return 3.1416 * radius * radius;
    }
};

int main() {
    vector<Shape*> dynamicShapes;

    dynamicShapes.push_back(new Rectangle(5, 4));
    dynamicShapes.push_back(new Circle(3));
    dynamicShapes.push_back(new Rectangle(6, 2));

    cout << "Dynamic Storage Areas:" << endl;
    for(int i = 0; i < dynamicShapes.size(); i++) {
        cout << dynamicShapes[i]->Area() << endl;
    }

    Shape* staticShapes[3];
    Rectangle r1(2, 3), r2(4, 5);
    Circle c1(2.5);

    staticShapes[0] = &r1;
    staticShapes[1] = &c1;
    staticShapes[2] = &r2;

    cout << "Static Storage Areas:" << endl;
    for(int i = 0; i < 3; i++) {
        cout << staticShapes[i]->Area() << endl;
    }

    for(int i = 0; i < dynamicShapes.size(); i++) {
        delete dynamicShapes[i];
    }

    return 0;
}