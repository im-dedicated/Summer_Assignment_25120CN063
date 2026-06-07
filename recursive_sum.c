#include <stdio.h>

int sumDigits(int n) {
    if (n == 0)
        return 0;
    return n % 10 + sumDigits(n / 10);
}

int main(void) {
    int num;
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1)
        return 1;
    if (num < 0)
        num = -num;
    printf("Sum of digits = %d\n", sumDigits(num));
    return 0;
}
