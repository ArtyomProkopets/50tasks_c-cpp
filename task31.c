// gcc -std=c17 -Wall -Wextra -o task31 task31.c && ./task31

#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int key;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

BSTNode *bst_insert(BSTNode *root, int key) {
    if (root == NULL) {
        BSTNode *node = malloc(sizeof(BSTNode));
        if (!node) { fprintf(stderr, "malloc failed\n"); exit(EXIT_FAILURE); }
        node->key = key;
        node->left = node->right = NULL;
        return node;
    }
    if (key < root->key) root->left = bst_insert(root->left, key);
    else if (key > root->key) root->right = bst_insert(root->right, key);
    return root;
}

void bst_inorder(BSTNode *root) {
    if (!root) return;
    bst_inorder(root->left);
    printf("%d ", root->key);
    bst_inorder(root->right);
}

int bst_contains(BSTNode *root, int key) {
    if (!root) return 0;
    if (root->key == key) return 1;
    return key < root->key ? bst_contains(root->left, key) : bst_contains(root->right, key);
}

void bst_free(BSTNode *root) {
    if (!root) return;
    bst_free(root->left);
    bst_free(root->right);
    free(root);
}

int main(void) {
    BSTNode *root = NULL;
    int values[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int n = (int)(sizeof(values) / sizeof(values[0]));
    for (int i = 0; i < n; i++) root = bst_insert(root, values[i]);

    printf("Симметричный обход (отсортированный порядок): ");
    bst_inorder(root);
    printf("\n");

    printf("contains(7) = %d, contains(99) = %d\n", bst_contains(root, 7), bst_contains(root, 99));

    bst_free(root);
    return 0;
}