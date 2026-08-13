// gcc -std=c17 -Wall -Wextra -o task16 task16.c && ./task16

#include <stdio.h>

double array_average(const int arr[], int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return n > 0 ? (double)sum / n : 0.0;
}

int array_max(const int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    return max;
}

int main(void) {
    int data[] = {4, 8, 15, 16, 23, 42};
    int n = (int)(sizeof(data) / sizeof(data[0]));
    printf("Среднее: %.3f\n", array_average(data, n));
    printf("Максимум: %d\n", array_max(data, n));
    return 0;
}