// gcc -std=c17 -Wall -Wextra -o task42 task42.c && ./task42

#include <iostream>
#include <vector>
#include <memory>

class Animal {
public:
    virtual void speak() const = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() const override { std::cout << "Гав!\n"; }
};

class Cat : public Animal {
public:
    void speak() const override { std::cout << "Мяу!\n"; }
};

int main() {
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());

    for (const auto& a : animals) {
        a->speak();
    }
    return 0;
}