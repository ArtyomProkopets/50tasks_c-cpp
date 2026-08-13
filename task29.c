// gcc -std=c17 -Wall -Wextra -o task29 task29.c && ./task29

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *list_push_front(Node *head, int value) {
    Node *node = malloc(sizeof(Node));
    if (!node) { fprintf(stderr, "malloc failed\n"); exit(EXIT_FAILURE); }
    node->value = value;
    node->next = head;
    return node;
}

Node *list_remove(Node *head, int value) {
    Node dummy;
    dummy.next = head;
    Node *prev = &dummy;
    Node *cur = head;
    while (cur) {
        if (cur->value == value) {
            prev->next = cur->next;
            free(cur);
            cur = prev->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return dummy.next;
}

int list_find(Node *head, int value) {
    for (Node *cur = head; cur; cur = cur->next) {
        if (cur->value == value) return 1;
    }
    return 0;
}

void list_print(Node *head) {
    for (Node *cur = head; cur; cur = cur->next) printf("%d -> ", cur->value);
    printf("NULL\n");
}

void list_free(Node *head) {
    while (head) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void) {
    Node *head = NULL;
    for (int i = 5; i >= 1; i--) head = list_push_front(head, i);
    list_print(head);

    printf("find(3) = %d, find(9) = %d\n", list_find(head, 3), list_find(head, 9));

    head = list_remove(head, 3);
    printf("После удаления 3: ");
    list_print(head);

    list_free(head);
    return 0;
}