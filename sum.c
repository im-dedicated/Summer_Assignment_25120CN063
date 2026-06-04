#include <stdio.h>

int main(void)
{
    int n, i, sum = 0;

    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        puts("Please enter a positive integer.");
        return 1;
    }

    for (i = 1; i <= n; ++i) {
        sum += i;
    }

    printf("Sum of first %d natural numbers is %d\n", n, sum);
    return 0;
}
