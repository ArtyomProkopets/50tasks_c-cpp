// gcc -std=c17 -Wall -Wextra -o task30 task30.c && ./task30

#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int value;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
} Stack;

void stack_init(Stack *s) { s->top = NULL; }

void stack_push(Stack *s, int value) {
    StackNode *node = malloc(sizeof(StackNode));
    if (!node) { fprintf(stderr, "malloc failed\n"); exit(EXIT_FAILURE); }
    node->value = value;
    node->next = s->top;
    s->top = node;
}

int stack_is_empty(const Stack *s) { return s->top == NULL; }

int stack_pop(Stack *s, int *out_value) {
    if (stack_is_empty(s)) return 0;
    StackNode *old_top = s->top;
    *out_value = old_top->value;
    s->top = old_top->next;
    free(old_top);
    return 1;
}

int stack_peek(const Stack *s, int *out_value) {
    if (stack_is_empty(s)) return 0;
    *out_value = s->top->value;
    return 1;
}

void stack_free(Stack *s) {
    int v;
    while (stack_pop(s, &v)) { }
}

int main(void) {
    Stack s;
    stack_init(&s);
    for (int i = 1; i <= 5; i++) stack_push(&s, i);

    int top;
    stack_peek(&s, &top);
    printf("Верхний элемент: %d\n", top);

    printf("Извлечение: ");
    int v;
    while (stack_pop(&s, &v)) printf("%d ", v);
    printf("\n");

    printf("Стек пуст: %s\n", stack_is_empty(&s) ? "да" : "нет");

    stack_free(&s);
    return 0;
}