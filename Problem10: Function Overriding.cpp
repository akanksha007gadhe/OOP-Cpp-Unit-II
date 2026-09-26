#include <iostream>

class Vehicle {
public:
    virtual void move() const {
        std::cout << "Vehicle travels\n";
    }

    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
public:
    void move() const override {
        std::cout << "Car travels on highways\n";
    }
};

class Boat : public Vehicle {
public:
    void move() const override {
        std::cout << "Boat travels on rivers\n";
    }
};

int main() {
    Car car;
    Boat boat;

    car.move();
    boat.move();

    return 0;
}
