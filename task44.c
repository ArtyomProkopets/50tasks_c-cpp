// gcc -std=c17 -Wall -Wextra -o task44 task44.c && ./task44

#include <iostream>
#include <vector>
#include <memory>

class Employee {
public:
    explicit Employee(std::string name) : name_(std::move(name)) {}
    virtual double salary() const = 0;
    void report() const { std::cout << name_ << ": " << salary() << " руб.\n"; }
    virtual ~Employee() = default;
protected:
    std::string name_;
};

class Manager : public Employee {
public:
    Manager(std::string name, double base, double bonus)
        : Employee(std::move(name)), base_(base), bonus_(bonus) {}
    double salary() const override { return base_ + bonus_; }
private:
    double base_, bonus_;
};

class Developer : public Employee {
public:
    Developer(std::string name, double base, int overtimeHours, double hourRate)
        : Employee(std::move(name)), base_(base), overtimeHours_(overtimeHours), hourRate_(hourRate) {}
    double salary() const override { return base_ + overtimeHours_ * hourRate_; }
private:
    double base_;
    int overtimeHours_;
    double hourRate_;
};

int main() {
    std::vector<std::unique_ptr<Employee>> staff;
    staff.push_back(std::make_unique<Manager>("Иванова А.", 80000, 15000));
    staff.push_back(std::make_unique<Developer>("Петров Б.", 90000, 10, 1200));

    double total = 0;
    for (const auto& e : staff) {
        e->report();
        total += e->salary();
    }
    std::cout << "Итого фонд оплаты: " << total << " руб.\n";
    return 0;
}