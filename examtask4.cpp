#include <iostream>
#include <string>

// Base class
class Vehicle {
private:
    std::string model;
    double speed; // Speed in km/h

public:
    // Setter for model
    void setModel(const std::string& m) {
        model = m;
    }

    // Getter for model
    std::string getModel() const {
        return model;
    }

    // Setter for speed
    void setSpeed(double s) {
        speed = s;
    }

    // Getter for speed
    double getSpeed() const {
        return speed;
    }

    // Pure virtual function for calculating time
    virtual double calculateTime(double distance) const = 0;

    // Virtual function for displaying details
    virtual void displayDetails() const = 0;

    // Virtual destructor
    virtual ~Vehicle() {}
};

// Derived class Car
class Car : public Vehicle {
public:
    // Calculate time taken for a certain distance for a Car
    double calculateTime(double distance) const override {
        if (getSpeed() > 0) {
            return distance / getSpeed();
        } else {
            std::cerr << "Speed must be greater than 0." << std::endl;
            return 0.0;
        }
    }

    // Display details specific to Car
    void displayDetails() const override {
        std::cout << "Car Model: " << getModel() << std::endl;
        std::cout << "Car Speed: " << getSpeed() << " km/h" << std::endl;
    }
};

// Derived class Bike
class Bike : public Vehicle {
public:
    // Calculate time taken for a certain distance for a Bike
    double calculateTime(double distance) const override {
        if (getSpeed() > 0) {
            return distance / getSpeed();
        } else {
            std::cerr << "Speed must be greater than 0." << std::endl;
            return 0.0;
        }
    }

    // Display details specific to Bike
    void displayDetails() const override {
        std::cout << "Bike Model: " << getModel() << std::endl;
        std::cout << "Bike Speed: " << getSpeed() << " km/h" << std::endl;
    }
};

int main() {
    // Create an array of Vehicle pointers
    const int vehicleCount = 2;
    Vehicle* vehicles[vehicleCount];

    // Instantiate Car and Bike objects
    Car myCar;
    myCar.setModel("Toyota Camry");
    myCar.setSpeed(120.0);

    Bike myBike;
    myBike.setModel("Yamaha R15");
    myBike.setSpeed(80.0);

    // Assign objects to Vehicle pointers
    vehicles[0] = &myCar;
    vehicles[1] = &myBike;

    // Demonstrate polymorphism by calling displayDetails() for each vehicle
    for (int i = 0; i < vehicleCount; ++i) {
        vehicles[i]->displayDetails();
        std::cout << std::endl;
    }

    return 0;
}
