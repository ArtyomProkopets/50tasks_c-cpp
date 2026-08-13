// gcc -std=c17 -Wall -Wextra -o task21 task21.c && ./task21

#include <stdio.h>
#include <string.h>

int count_words(const char *s) {
    int count = 0;
    int in_word = 0;
    for (; *s; s++) {
        if (*s != ' ' && *s != '\t' && *s != '\n') {
            if (!in_word) { count++; in_word = 1; }
        } else {
            in_word = 0;
        }
    }
    return count;
}

void reverse_in_place(char *s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len / 2; i++) {
        char tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
}

int main(void) {
    const char *text = "  привет   мир  из C  ";
    printf("Слов: %d\n", count_words(text));

    char buf[] = "Programming";
    reverse_in_place(buf);
    printf("Реверс: %s\n", buf);
    return 0;
}