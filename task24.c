// gcc -std=c17 -Wall -Wextra -o task24 task24.c && ./task24

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    const char *filename = "sales.csv";
    FILE *f = fopen(filename, "w");
    if (!f) { perror("open"); return 1; }
    fprintf(f, "Moscow,120000\nSPb,95000\nKazan,54000\nMoscow,30000\n");
    fclose(f);

    f = fopen(filename, "r");
    if (!f) { perror("open"); return 1; }

    char line[128];
    double total = 0.0;
    int lines = 0;
    while (fgets(line, sizeof(line), f)) {
        char *city = strtok(line, ",\n");
        char *amount_str = strtok(NULL, ",\n");
        if (city == NULL || amount_str == NULL) continue;
        double amount = atof(amount_str);
        printf("%-10s %10.2f\n", city, amount);
        total += amount;
        lines++;
    }
    fclose(f);

    printf("Обработано строк: %d, сумма: %.2f\n", lines, total);
    return 0;
}