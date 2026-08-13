// gcc -std=c17 -Wall -Wextra -o task07 task07.c && ./task07


#include <stdio.h>
#define N 4

void print_matrix(int m[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%4d", m[i][j]);
        printf("\n");
    }
}

void transpose(int m[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            int tmp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = tmp;
        }
}

int main_diagonal_sum(int m[N][N])
{
    int sum = 0;
    for (int i = 0; i < N; i++) sum += m[i][i];
    return sum;
}

int anti_diagonal_sum(int m[N][N])
{
    int sum = 0;
    for (int i = 0; i < N; i++) sum += m[i][N - 1 - i];
    return sum;
}

int main(void)
{
    int matrix[N][N] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Исходная матрица:\n");
    print_matrix(matrix);

    printf("\nСумма главной диагонали: %d\n", main_diagonal_sum(matrix));
    printf("Сумма побочной диагонали: %d\n", anti_diagonal_sum(matrix));

    transpose(matrix);
    printf("\nТранспонированная матрица:\n");
    print_matrix(matrix);

    return 0;
}