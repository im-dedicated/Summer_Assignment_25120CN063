#include <stdio.h>

int main(void)
{
    double x;
    int n;
    double result = 1.0;
    int i;

    printf("Enter base x: ");
    if (scanf("%lf", &x) != 1) {
        return 1;
    }

    printf("Enter exponent n: ");
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    if (n < 0) {
        for (i = 0; i < -n; i++) {
            result *= x;
        }
        if (x != 0.0) {
            result = 1.0 / result;
        } else {
            printf("Cannot raise 0 to a negative power.\n");
            return 1;
        }
    } else {
        for (i = 0; i < n; i++) {
            result *= x;
        }
    }

    printf("Result: %.6g\n", result);
    return 0;
}
