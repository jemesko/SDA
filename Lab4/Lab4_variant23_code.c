#include <math.h>
#include <stdio.h>

int main(void)
{
    double a[10][10];
    int m, n, i, j, left, right, middle;

    printf("Введіть m і n (від 1 до 10): ");
    int read = scanf("%d%d", &m, &n);
    if (read != 2) {
        printf("Введіть два цілі числа.\n");
        return 1;
    }
    if (m < 1 || m > 10 || n < 1 || n > 10) {
        printf("Неправильні розміри.\n");
        return 1;
    }

    printf("Введіть матрицю:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            read = scanf("%lf", &a[i][j]);
            if (read != 1) {
                printf("Некоректне число в матриці.\n");
                    return 1;
            }
            if (isfinite(a[i][j]) == 0) {
                printf("Введіть скінченне число.\n");
                return 1;
            }
        }
    }

    for (j = 1; j < n; j++) {
        if (a[m - 1][j] > a[m - 1][j - 1]) {
            printf("Останній рядок має бути незростаючим.\n");
            return 1;
        }
    }
    for (i = 1; i < m; i++) {
        if (a[i][0] > a[i - 1][0]) {
            printf("Перший стовпчик має бути незростаючим.\n");
            return 1;
        }
    }

    printf("Матриця:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf("%7.2f", a[i][j]);
        printf("\n");
    }

    left = 0;
    right = n - 1;
    while (left <= right) {
        middle = (left + right) / 2;
        if (a[m - 1][middle] > 5)
            left = middle + 1;
        else if (a[m - 1][middle] < 0)
            right = middle - 1;
        else
            break;
    }
    if (left <= right)
        printf("Останній рядок: a[%d][%d] = %.2f\n",
            m, middle + 1, a[m - 1][middle]);
    else
        printf("Останній рядок: чисел з [0; 5] немає.\n");
    left = 0;
    right = m - 1;
    while (left <= right) {
        middle = (left + right) / 2;
        if (a[middle][0] > 5)
            left = middle + 1;
        else if (a[middle][0] < 0)
            right = middle - 1;
        else
            break;
    }
    if (left <= right)
        printf("Перший стовпчик: a[%d][1] = %.2f\n",
            middle + 1, a[middle][0]);
    else
        printf("Перший стовпчик: чисел з [0; 5] немає.\n");
    return 0;
}