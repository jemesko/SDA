#include <stdio.h>

int main(void) {
    double x, y;

    printf("Enter x: ");

    if (scanf("%lf", &x) != 1) {
        printf("Invalid input\n");
    }
    else if (x <= -41) {
        y = 13 * x * x / 11 - 6;
        printf("Y = %f\n", y);
    }
    else if (x > -21) {
        if (x <= 3) {
            y = -14 * x - 20;
            printf("Y = %f\n", y);
        }
        else if (x > 12) {
            y = -14 * x - 20;
            printf("Y = %f\n", y);
        }
        else {
            printf("Function undefined\n");
        }
    }
    else {
        printf("Function undefined\n");
    }

    return 0;
}
