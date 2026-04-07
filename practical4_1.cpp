#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;

public:
    
    DynamicArray() {
        arr = NULL;
        size = 0;
    }

    
    void insert(int value) {
        int* newArr = new int[size + 1];

        
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        
        newArr[size] = value;

        
        delete[] arr;

        
        arr = newArr;
        size++;

        cout << "Element inserted successfully!\n";
    }

    
    void deleteAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position!\n";
            return;
        }

        int* newArr = new int[size - 1];

        for (int i = 0, j = 0; i < size; i++) {
            if (i != pos) {
                newArr[j++] = arr[i];
            }
        }

        delete[] arr;
        arr = newArr;
        size--;

        cout << "Element deleted successfully!\n";
    }

    
    void display() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }

        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray da;
    int choice, value, pos;

    do {
        cout << "\n--- MENU ---";
        cout << "\n1. Insert Element";
        cout << "\n2. Delete Element";
        cout << "\n3. Display Array";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            da.insert(value);
            break;

        case 2:
            cout << "Enter position to delete (0-based index): ";
            cin >> pos;
            da.deleteAt(pos);
            break;

        case 3:
            da.display();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}