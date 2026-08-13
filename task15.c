// gcc -std=c17 -Wall -Wextra -o task15 task15.c && ./task15

#include <stdio.h>

void divide(int a, int b, int *quotient, int *remainder, int *ok) {
    if (b == 0) {
        *ok = 0;
        return;
    }
    *quotient = a / b;
    *remainder = a % b;
    *ok = 1;
}

int main(void) {
    int q, r, ok;
    divide(17, 5, &q, &r, &ok);
    if (ok) printf("17 / 5 = %d, остаток %d\n", q, r);

    divide(10, 0, &q, &r, &ok);
    if (!ok) printf("Деление на ноль обнаружено и обработано\n");
    return 0;
}
