#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    
    Point(int xVal = 0, int yVal = 0) {
        x = xVal;
        y = yVal;
    }

   
    Point& move(int dx, int dy) {
        this->x += dx;
        this->y += dy;
        return *this; 
    }

    
    void display() {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }

    
    friend void modifyPoint(Point* p);
};


void modifyPoint(Point* p) {
    p->move(5, 5); 
}

int main() {
    Point p(2, 3);

    cout << "Initial Point: ";
    p.display();

    
    p.move(2, 3).move(-1, 4);

    cout << "After chainable move: ";
    p.display();

    
    modifyPoint(&p);

    cout << "After modifyPoint(): ";
    p.display();

    return 0;
}