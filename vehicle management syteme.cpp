#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Vehicle {
protected:
    string make;
    string model;
    int year;
    double price;

public:
    void setMake(const string& m) {
        make = m;
    }
    void setModel(const string& m) {
        model = m;
    }
    void setYear(int y) {
        year = y;
    }
    void setPrice(double p) {
        price = p;
    }

    string getMake() const {
        return make;
    }
    string getModel() const {
        return model;
    }
    int getYear() const {
        return year;
    }
    double getPrice() const {
        return price;
    }

    virtual float calculateTax() const {
        return 0.0f; // Default implementation for base class
    }

    virtual void displayDetails() const {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
        cout << "Tax: " << calculateTax() << endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;
    float taxRate = 0.05;

public:
    void setNumDoors(int n) {
        numDoors = n;
    }
    int getNumDoors() const {
        return numDoors;
    }

    float calculateTax() const override {
        return taxRate * getPrice();
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Number of doors: " << numDoors << endl;
    }
};

class Truck : public Vehicle {
private:
    int payload;
    int towingCapacity;
    float taxRate = 0.1;

public:
    void setPayload(int p) {
        payload = p;
    }
    void setTowingCapacity(int c) {
        towingCapacity = c;
    }

    int getPayload() const {
        return payload;
    }
    int getTowingCapacity() const {
        return towingCapacity;
    }

    float calculateTax() const override {
        return taxRate * getPrice();
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Payload: " << payload << " tons" << endl;
        cout << "Towing Capacity: " << towingCapacity << " lbs" << endl;
    }
};

int main() {
    const int max_capacity = 100;
    unique_ptr<Vehicle> fleet[max_capacity];
    int fleetSize = 0;
    int userInput;
    string userType;
    string m1, m2;
    int y, p, d;
    while (true) {
        cout << "Welcome to the vehicle management system!" << endl;
        cout << "Menu: " << endl;
        cout << "1. Add vehicle" << endl;
        cout << "2. Remove vehicle" << endl;
        cout << "3. Search for vehicle" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userInput;

        if (userInput == 1) {
            cout << "Enter vehicle type (Car / Truck): ";
            cin >> userType;
            if (userType == "Car") {
                Car car;
                cout << "Enter vehicle make: ";
                cin >> m1;
                car.setMake(m1);
                cout << "Enter vehicle model: ";
                cin >> m2;
                car.setModel(m2);
                cout << "Enter vehicle year: ";
                cin >> y;
                car.setYear(y);
                cout << "Enter vehicle price: ";
                cin >> p;
                car.setPrice(p);
                cout << "Enter number of doors: ";
                cin >> d;
                car.setNumDoors(d);
                fleet[fleetSize++] = make_unique<Car>(car);
                cout << "Car added to fleet." << endl;
            }
            else if (userType == "Truck") {
                Truck truck;
                cout << "Enter truck make: ";
                cin >> m1;
                truck.setMake(m1);
                cout << "Enter truck model: ";
                cin >> m2;
                truck.setModel(m2);
                cout << "Enter truck year: ";
                cin >> y;
                truck.setYear(y);
                cout << "Enter truck price: ";
                cin >> p;
                truck.setPrice(p);
                int payload;
                cout << "Enter truck payload (tons): ";
                cin >> payload;
                truck.setPayload(payload);
                int towingCapacity;
                cout << "Enter truck towing capacity (lbs): ";
                cin >> towingCapacity;
                truck.setTowingCapacity(towingCapacity);
                fleet[fleetSize++] = make_unique<Truck>(truck);
                cout << "Truck added to fleet." << endl;
            }
            else {
                cout << "Invalid vehicle type. Please enter Car or Truck." << endl;
            }
        }
        else if (userInput == 2) {
            if (fleetSize == 0) {
                cout << "Fleet is empty. No vehicle to remove." << endl;
            } else {
                int index;
                cout << "Enter index of the vehicle to remove (1-" << fleetSize << "): ";
                cin >> index;
                if (index < 1 || index > fleetSize) {
                    cout << "Invalid index. Please enter a valid index." << endl;
                } else {
                    for (int i = index - 1; i < fleetSize - 1; ++i) {
                        fleet[i] = move(fleet[i + 1]);
                    }
                    fleetSize--;
                    cout << "Vehicle removed from fleet." << endl;
                }
            }
        }
        else if (userInput == 3) {
            string searchMake;
            cout << "Enter make of the vehicle to search: ";
            cin >> searchMake;

            bool found = false;
            for (int i = 0; i < fleetSize; ++i) {
                if (fleet[i]->getMake() == searchMake) {
                    cout << "\nVehicle found:" << endl;
                    fleet[i]->displayDetails();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Vehicle with make \"" << searchMake << "\" not found in the fleet." << endl;
            }
        }
        else if (userInput == 4) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid input. Please enter a number from 1 to 4." << endl;
        }
    }

    return 0;
}
