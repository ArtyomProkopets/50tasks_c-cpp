// gcc -std=c17 -Wall -Wextra -o task22 task22.c && ./task22

#include <stdio.h>

int main(void) {
    const char *filename = "students.txt";

    FILE *out = fopen(filename, "w");
    if (out == NULL) {
        perror("Не удалось открыть файл на запись");
        return 1;
    }
    fprintf(out, "Ivanov 85\nPetrov 92\nSidorov 78\n");
    fclose(out);

    FILE *in = fopen(filename, "r");
    if (in == NULL) {
        perror("Не удалось открыть файл на чтение");
        return 1;
    }

    char name[64];
    int score;
    long total = 0;
    int count = 0;
    while (fscanf(in, "%63s %d", name, &score) == 2) {
        printf("%-10s %d\n", name, score);
        total += score;
        count++;
    }
    fclose(in);

    if (count > 0) {
        printf("Средний балл: %.2f\n", (double)total / count);
    }
    return 0;
}