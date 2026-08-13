// gcc -std=c17 -Wall -Wextra -o task03 task03.c && ./task03

#include <stdio.h>

int main(void)
{
    int a = 17, b = 5;

    int quotient = a / b;
    int remainder = a % b;
    double real_division = (double) a / b;

    unsigned int x = 0b00110110; /* 54  */
    unsigned int y = 0b00010111; /* 23  */

    unsigned int bit_and = x & y;
    unsigned int bit_or  = x | y;
    unsigned int bit_xor = x ^ y;
    unsigned int shift_left  = x << 2;
    unsigned int shift_right = x >> 2;

    printf("a = %d, b = %d\n", a, b);
    printf("a / b (int)    = %d\n", quotient);
    printf("a %% b          = %d\n", remainder);
    printf("a / b (double) = %.4f\n", real_division);

    printf("\nx = %u, y = %u\n", x, y);
    printf("x & y  = %u\n", bit_and);
    printf("x | y  = %u\n", bit_or);
    printf("x ^ y  = %u\n", bit_xor);
    printf("x << 2 = %u\n", shift_left);
    printf("x >> 2 = %u\n", shift_right);

    return 0;
}