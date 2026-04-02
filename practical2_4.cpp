#include <iostream>
#include <vector>
using namespace std;

class Item {
private:
    int itemID;
    string itemName;
    double price;
    int quantity;

public:
    Item() {
        itemID = 0;
        itemName = "Default Item";
        price = 0.0;
        quantity = 0;
    }

    Item(int id, string name, double p, int q = 0) {
        itemID = id;
        itemName = name;
        price = (p >= 0) ? p : 0;
        quantity = (q >= 0) ? q : 0;
    }

    void addStock(int qty) {
        if (qty > 0)
            quantity += qty;
        else
            cout << "Invalid stock addition\n";
    }

    void sellItem(int qty) {
        if (qty <= 0) {
            cout << "Invalid sale quantity\n";
        } else if (qty > quantity) {
            cout << "Insufficient stock\n";
        } else {
            quantity -= qty;
        }
    }

    void display() const {
        cout << "\nItem ID: " << itemID;
        cout << "\nName: " << itemName;
        cout << "\nPrice: " << price;
        cout << "\nQuantity: " << quantity << endl;
    }
};

int main() {
    vector<Item> inventory;

    Item i1(101, "Laptop", 55000, 10);
    Item i2(102, "Mouse", 500);
    Item i3(103, "Keyboard", 1500, 5);

    inventory.push_back(i1);
    inventory.push_back(i2);
    inventory.push_back(i3);

    inventory[0].addStock(5);
    inventory[0].sellItem(8);

    inventory[1].addStock(20);
    inventory[1].sellItem(25);

    inventory[2].sellItem(3);
    inventory[2].addStock(-2);

    for (const auto &item : inventory) {
        item.display();
    }

    return 0;
}