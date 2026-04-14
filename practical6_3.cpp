#include <iostream>
#include <vector>
using namespace std;

class Fuel {
protected:
    string fuelType;
public:
    Fuel(string f) {
        fuelType = f;
    }
    void displayFuel() {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Brand {
protected:
    string brandName;
public:
    Brand(string b) {
        brandName = b;
    }
    void displayBrand() {
        cout << "Brand: " << brandName << endl;
    }
};

class Car : public Fuel, public Brand {
    int carID;
public:
    Car(int id, string f, string b) : Fuel(f), Brand(b) {
        carID = id;
    }
    int getID() {
        return carID;
    }
    void displayCar() {
        cout << "Car ID: " << carID << endl;
        displayBrand();
        displayFuel();
    }
};

Car* findCarByID(vector<Car*> &queue, int id) {
    for (auto c : queue) {
        if (c->getID() == id)
            return c;
    }
    return NULL;
}

int main() {
    vector<Car*> serviceQueue;

    serviceQueue.push_back(new Car(1, "Petrol", "Toyota"));
    serviceQueue.push_back(new Car(2, "Diesel", "Honda"));
    serviceQueue.push_back(new Car(3, "Electric", "Tesla"));

    cout << "Service Queue (Dynamic):" << endl;
    for (auto c : serviceQueue) {
        c->displayCar();
        cout << endl;
    }

    int searchID = 2;
    Car* result = findCarByID(serviceQueue, searchID);

    if (result) {
        cout << "Car Found:" << endl;
        result->displayCar();
    } else {
        cout << "Car not found" << endl;
    }

    Car staticQueue[2] = {
        Car(4, "Petrol", "Hyundai"),
        Car(5, "Diesel", "Ford")
    };

    cout << endl << "Static Queue:" << endl;
    for (int i = 0; i < 2; i++) {
        staticQueue[i].displayCar();
        cout << endl;
    }

    for (auto c : serviceQueue) {
        delete c;
    }

    return 0;
}