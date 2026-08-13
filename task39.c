// gcc -std=c17 -Wall -Wextra -o task39 task39.c && ./task39

#include <iostream>
#include <sstream>

class Fraction {
public:
    Fraction(int num = 0, int den = 1) : num_(num), den_(den) {}

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.num_ << "/" << f.den_;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Fraction& f) {
        char slash;
        is >> f.num_ >> slash >> f.den_;
        return is;
    }

private:
    int num_, den_;
};

int main() {
    Fraction f1(3, 4);
    std::cout << "f1 = " << f1 << '\n';

    std::istringstream input("7/8");
    Fraction f2;
    input >> f2;
    std::cout << "f2 (прочитано из потока) = " << f2 << '\n';

    return 0;
}
