// gcc -std=c17 -Wall -Wextra -o task26 task26.c && ./task26

#include <stdio.h>

typedef struct {
    double re;
    double im;
} Complex;

Complex complex_add(Complex a, Complex b) {
    Complex r = { a.re + b.re, a.im + b.im };
    return r;
}

Complex complex_mul(Complex a, Complex b) {
    Complex r;
    r.re = a.re * b.re - a.im * b.im;
    r.im = a.re * b.im + a.im * b.re;
    return r;
}

void complex_print(Complex c) {
    printf("%.2f %+.2fi\n", c.re, c.im);
}

int main(void) {
    Complex a = {2.0, 3.0};
    Complex b = {1.0, -4.0};

    Complex sum = complex_add(a, b);
    Complex prod = complex_mul(a, b);

    printf("a + b = "); complex_print(sum);
    printf("a * b = "); complex_print(prod);
    return 0;
}
