// gcc -std=c17 -Wall -Wextra -o task06 task06.c && ./task06

#include <stdio.h>

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int linear_search(const int arr[], int n, int target)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

void print_array(const int arr[], int n)
{
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    int arr[] = {9, 3, 7, 1, 5, 3, 8};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));

    printf("До сортировки: ");
    print_array(arr, n);

    insertion_sort(arr, n);

    printf("После сортировки: ");
    print_array(arr, n);

    int target = 7;
    int idx = linear_search(arr, n, target);
    if (idx != -1) printf("Значение %d найдено по индексу %d\n", target, idx);

    int missing = 42;
    idx = linear_search(arr, n, missing);
    printf("Поиск %d вернул индекс %d (ожидается -1)\n", missing, idx);

    return 0;
}