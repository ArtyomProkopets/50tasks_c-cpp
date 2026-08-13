// gcc -std=c17 -Wall -Wextra -o task40 task40.c && ./task40

#include <iostream>

class Shape {
public:
    virtual double area() const = 0;
    virtual void describe() const {
        std::cout << "Фигура с площадью " << area() << '\n';
    }
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : radius_(radius) {}
    double area() const override { return 3.14159265358979 * radius_ * radius_; }
    void describe() const override {
        std::cout << "Круг радиусом " << radius_ << ", площадь = " << area() << '\n';
    }
private:
    double radius_;
};

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width_(w), height_(h) {}
    double area() const override { return width_ * height_; }
    void describe() const override {
        std::cout << "Прямоугольник " << width_ << "x" << height_ << ", площадь = " << area() << '\n';
    }
private:
    double width_, height_;
};

int main() {
    Circle c(3.0);
    Rectangle r(4.0, 5.0);

    c.describe();
    r.describe();

    return 0;
}
