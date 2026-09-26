#include <iostream>
#include <string>
#include <utility>

class Vehicle {
protected:
    std::string registrationNumber;
    double ratePerDay;

public:
    Vehicle(std::string registration, double rate)
        : registrationNumber(std::move(registration)), ratePerDay(rate) {}

    virtual double calculateRent(int days) const {
        return ratePerDay * days;
    }

    virtual void display() const {
        std::cout << "Registration: " << registrationNumber << '\n';
        std::cout << "Rate per day: " << ratePerDay << '\n';
    }

    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
private:
    int numberOfDoors;

public:
    Car(std::string registration, double rate, int doors)
        : Vehicle(std::move(registration), rate), numberOfDoors(doors) {}

    void display() const override {
        Vehicle::display();
        std::cout << "Doors: " << numberOfDoors << '\n';
    }
};

class Bike : public Vehicle {
private:
    int engineCapacity;

public:
    Bike(std::string registration, double rate, int capacity)
        : Vehicle(std::move(registration), rate), engineCapacity(capacity) {}

    double calculateRent(int days) const override {
        return ratePerDay * days * 0.9;
    }

    void display() const override {
        Vehicle::display();
        std::cout << "Engine Capacity: " << engineCapacity << " cc\n";
    }
};

int main() {
    Car car("MH14EF2468", 2500.0, 4);
    Bike bike("MH14GH1357", 950.0, 180);

    std::cout << "Car Details\n";
    car.display();
    std::cout << "Rent for 4 days: " << car.calculateRent(4) << "\n\n";

    std::cout << "Bike Details\n";
    bike.display();
    std::cout << "Rent for 4 days: " << bike.calculateRent(4) << '\n';

    return 0;
}
