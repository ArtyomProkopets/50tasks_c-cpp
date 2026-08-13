// gcc -std=c17 -Wall -Wextra -o task11 task11.c && ./task11

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} IntArray;

void array_init(IntArray *arr, size_t initial_capacity)
{
    arr->data = malloc(initial_capacity * sizeof(int));
    if (arr->data == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }
    arr->size = 0;
    arr->capacity = initial_capacity;
}

void array_push(IntArray *arr, int value)
{
    if (arr->size == arr->capacity) {
        size_t new_capacity = arr->capacity * 2;
        int *new_data = realloc(arr->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            fprintf(stderr, "Ошибка перевыделения памяти\n");
            free(arr->data);
            exit(EXIT_FAILURE);
        }
        arr->data = new_data;
        arr->capacity = new_capacity;
    }
    arr->data[arr->size++] = value;
}

void array_free(IntArray *arr)
{
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int main(void)
{
    IntArray arr;
    array_init(&arr, 2);

    for (int i = 1; i <= 10; i++) {
        array_push(&arr, i * i);
        printf("push(%d): size=%zu capacity=%zu\n", i * i, arr.size, arr.capacity);
    }

    printf("\nСодержимое: ");
    for (size_t i = 0; i < arr.size; i++) printf("%d ", arr.data[i]);
    printf("\n");

    array_free(&arr);
    return 0;
}