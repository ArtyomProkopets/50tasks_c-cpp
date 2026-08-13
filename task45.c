// gcc -std=c17 -Wall -Wextra -o task45 task45.c && ./task45

#include <iostream>

class Device {
public:
    explicit Device(std::string name) : name_(std::move(name)) {}
    void powerOn() const { std::cout << name_ << ": включение\n"; }
protected:
    std::string name_;
};

class Printer : virtual public Device {
public:
    explicit Printer(std::string name) : Device(std::move(name)) {}
    void print() const { std::cout << name_ << ": печать документа\n"; }
};

class Scanner : virtual public Device {
public:
    explicit Scanner(std::string name) : Device(std::move(name)) {}
    void scan() const { std::cout << name_ << ": сканирование документа\n"; }
};

class MFP : public Printer, public Scanner {
public:
    explicit MFP(std::string name) : Device(name), Printer(name), Scanner(name) {}
};

int main() {
    MFP device("HP LaserJet MFP");
    device.powerOn();
    device.print();
    device.scan();
    return 0;
}