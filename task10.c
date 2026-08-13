// gcc -std=c17 -Wall -Wextra -o task10 task10.c && ./task10

#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void rotate_left(int *arr, int n)
{
    if (n <= 1) return;
    int first = *arr;
    int *p = arr;
    while (p < arr + n - 1) {
        *p = *(p + 1);
        p++;
    }
    *(arr + n - 1) = first;
}

int main(void)
{
    int x = 5, y = 10;
    printf("До swap: x=%d, y=%d\n", x, y);
    swap(&x, &y);
    printf("После swap: x=%d, y=%d\n", x, y);

    int arr[] = {1, 2, 3, 4, 5};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));

    printf("\nДо сдвига: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    rotate_left(arr, n);

    printf("После сдвига: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}