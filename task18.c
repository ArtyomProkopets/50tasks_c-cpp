// gcc -std=c17 -Wall -Wextra -o task18 task18.c && ./task18

#include <stdio.h>

void hanoi(int n, char from, char aux, char to, long *moves) {
    if (n == 0) return;
    hanoi(n - 1, from, to, aux, moves);
    printf("Переместить диск %d: %c -> %c\n", n, from, to);
    (*moves)++;
    hanoi(n - 1, aux, from, to, moves);
}

int main(void) {
    int n = 3;
    long moves = 0;
    hanoi(n, 'A', 'B', 'C', &moves);
    printf("Всего перемещений: %ld (ожидается 2^%d - 1 = %d)\n", moves, n, (1 << n) - 1);
    return 0;
}
