#include <stdio.h>

int fact(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main() {
    int num, n, r, sum = 0;

    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1) return 0;

    if (num < 0) {
        printf("Negative numbers not allowed.\n");
        return 0;
    }

    n = num;
    while (n > 0) {
        r = n % 10;
        sum += fact(r);
        n /= 10;
    }

    if (sum == num)
        printf("%d is a Strong number.\n", num);
    else
        printf("%d is not a Strong number.\n", num);

    return 0;
}
