#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int choice;
    string name, searchName;
    int quantity;
    float price;

    do {
        cout << "\n1. Add Item\n2. View All Items\n3. Search Item\n0. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            ofstream file("inventory.txt", ios::app);
            cout << "Enter item name: ";
            cin >> name;
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter price: ";
            cin >> price;
            file << name << " " << quantity << " " << price << endl;
            file.close();
        }

        else if (choice == 2) {
            ifstream file("inventory.txt");
            while (file >> name >> quantity >> price) {
                cout << name << " " << quantity << " " << price << endl;
            }
            file.close();
        }

        else if (choice == 3) {
            ifstream file("inventory.txt");
            cout << "Enter item name to search: ";
            cin >> searchName;
            bool found = false;

            while (file >> name >> quantity >> price) {
                if (name == searchName) {
                    cout << name << " " << quantity << " " << price << endl;
                    found = true;
                }
            }

            if (!found)
                cout << "Item not found\n";

            file.close();
        }

    } while (choice != 0);

    return 0;
}