#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base class constructor\n";
    }

    ~Base() {
        std::cout << "Base class destructor\n";
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived class constructor\n";
    }

    ~Derived() {
        std::cout << "Derived class destructor\n";
    }
};

int main() {
    Derived object;
    return 0;
}
