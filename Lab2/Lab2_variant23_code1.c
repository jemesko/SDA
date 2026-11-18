#include <stdio.h>

int main(void)
{
    int n, i, j;
    double x = 1.5, s = 0, t;
    long long count = 0;

    printf("Введіть n: ");
    scanf("%d", &n);

    count += 2;
    count += 2;
    for (i = 0; i <= n; i++) {
        t = 1;
        count++;
        count += 2;
        for (j = 1; j <= i; j++) {
            t = -t * x * x / j;
            count += 5;
            count += 3;
        }
        s = s + t;
        count += 2;
        count += 3;
    }

    printf("S = %.7f\n", s);
    printf("Кількість операцій: %lld\n", count);
    return 0;
}