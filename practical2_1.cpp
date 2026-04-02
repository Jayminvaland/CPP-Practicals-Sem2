#include <iostream>
using namespace std;

class Rectangle {
private:
    float length;
    float width;

public:
    
    void setDimensions(float l, float w) {
        length = l;
        width = w;
    }

    
    void updateDimensions() {
        cout << "Enter new length: ";
        cin >> length;
        cout << "Enter new width: ";
        cin >> width;
    }

    
    float getArea() {
        return length * width;
    }

    
    float getPerimeter() {
        return 2 * (length + width);
    }

    
    void display() {
        cout << "\nLength: " << length;
        cout << "\nWidth: " << width;
        cout << "\nArea: " << getArea();
        cout << "\nPerimeter: " << getPerimeter() << endl;
    }
};

int main() {
    Rectangle r[100];
    int count = 0;
    int choice, index;
    float l, w;

    do {
        cout << "\n--- MENU ---";
        cout << "\n1. Add Rectangle";
        cout << "\n2. Update Rectangle";
        cout << "\n3. Display All Rectangles";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter length: ";
            cin >> l;
            cout << "Enter width: ";
            cin >> w;
            r[count].setDimensions(l, w);
            count++;
            cout << "Rectangle added.\n";
            break;

        case 2:
            cout << "Enter rectangle index (0 to " << count - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < count) {
                r[index].updateDimensions();
            } else {
                cout << "Invalid index.\n";
            }
            break;

        case 3:
            for (int i = 0; i < count; i++) {
                cout << "\nRectangle " << i << ":";
                r[i].display();
            }
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}