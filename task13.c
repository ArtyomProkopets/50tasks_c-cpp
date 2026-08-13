// gcc -std=c17 -Wall -Wextra -o task13 task13.c && ./task13

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 4

int cmp_strings(const void *a, const void *b) {
    const char *sa = *(const char * const *)a;
    const char *sb = *(const char * const *)b;
    return strcmp(sa, sb);
}

int main(void) {
    char *names[N] = {"Ivanov", "Petrov", "Alekseev", "Dmitriev"};
    printf("До сортировки:\n");
    for (int i = 0; i < N; i++) printf("  %s\n", names[i]);

    qsort(names, N, sizeof(char *), cmp_strings);

    printf("После сортировки (указатели переставлены, строки не копировались):\n");
    for (int i = 0; i < N; i++) printf("  %s\n", names[i]);
    return 0;
}