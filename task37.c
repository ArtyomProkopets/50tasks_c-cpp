// gcc -std=c17 -Wall -Wextra -o task37 task37.c && ./task37

#include <iostream>

class Vector2D {
public:
    Vector2D(double x = 0.0, double y = 0.0) : x_(x), y_(y) {}

    Vector2D operator+(const Vector2D& other) const { return Vector2D(x_ + other.x_, y_ + other.y_); }
    Vector2D operator-(const Vector2D& other) const { return Vector2D(x_ - other.x_, y_ - other.y_); }
    Vector2D operator*(double scalar) const { return Vector2D(x_ * scalar, y_ * scalar); }
    bool operator==(const Vector2D& other) const { return x_ == other.x_ && y_ == other.y_; }

    void print() const { std::cout << "(" << x_ << ", " << y_ << ")"; }

private:
    double x_, y_;
};

int main() {
    Vector2D a(2.0, 3.0);
    Vector2D b(1.0, -1.0);

    Vector2D sum = a + b;
    Vector2D diff = a - b;
    Vector2D scaled = a * 2.0;

    std::cout << "a + b = "; sum.print(); std::cout << '\n';
    std::cout << "a - b = "; diff.print(); std::cout << '\n';
    std::cout << "a * 2 = "; scaled.print(); std::cout << '\n';
    std::cout << "a == a: " << std::boolalpha << (a == a) << '\n';
    std::cout << "a == b: " << std::boolalpha << (a == b) << '\n';

    return 0;
}
