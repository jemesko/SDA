#include <stdio.h>

int main(void)
{
    int n, i;
    double x = 1.5, s = 1, t = 1;
    long long count = 0;

    printf("Введіть n: ");
    scanf("%d", &n);

    count += 3;
    count += 2;
    for (i = 1; i <= n; i++) {
        t = -t * x * x / i;
        count += 5;
        s = s + t;
        count += 2;
        count += 3;
    }

    printf("S = %.7f\n", s);
    printf("Кількість операцій: %lld\n", count);
    return 0;
}