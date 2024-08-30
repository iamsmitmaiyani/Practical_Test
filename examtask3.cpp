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
};

int main() {
    // Create objects of Car and Bike
    Car myCar;
    Bike myBike;

    // Set attributes for Car
    myCar.setModel("Toyota Camry");
    myCar.setSpeed(120.0); // Speed in km/h

    // Set attributes for Bike
    myBike.setModel("Yamaha R15");
    myBike.setSpeed(80.0); // Speed in km/h

    // Define a distance
    double distance = 240.0; // Distance in km

    // Calculate and display time for Car
    std::cout << "Car Model: " << myCar.getModel() << std::endl;
    std::cout << "Time taken by Car to travel " << distance << " km: " 
              << myCar.calculateTime(distance) << " hours" << std::endl;

    // Calculate and display time for Bike
    std::cout << "Bike Model: " << myBike.getModel() << std::endl;
    std::cout << "Time taken by Bike to travel " << distance << " km: " 
              << myBike.calculateTime(distance) << " hours" << std::endl;

    return 0;
}
