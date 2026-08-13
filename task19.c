// gcc -std=c17 -Wall -Wextra -o task19 task19.c && ./task19

#include <stdio.h>
#include <stdarg.h>

typedef int (*CompareFn)(int, int);

int less_than(int a, int b) { return a < b; }
int greater_than(int a, int b) { return a > b; }

int find_extreme(const int *arr, int n, CompareFn better) {
    int result = arr[0];
    for (int i = 1; i < n; i++) if (better(arr[i], result)) result = arr[i];
    return result;
}

int sum_variadic(int count, ...) {
    va_list args;
    va_start(args, count);
    int total = 0;
    for (int i = 0; i < count; i++) total += va_arg(args, int);
    va_end(args);
    return total;
}

int main(void) {
    int arr[] = {5, 2, 9, 1, 7};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));

    printf("Минимум: %d\n", find_extreme(arr, n, less_than));
    printf("Максимум: %d\n", find_extreme(arr, n, greater_than));

    printf("Сумма(1,2,3): %d\n", sum_variadic(3, 1, 2, 3));
    printf("Сумма(10,20,30,40): %d\n", sum_variadic(4, 10, 20, 30, 40));
    return 0;
}
