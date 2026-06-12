#include <stdio.h>

int isPerfect(int n)
{
    int sum = 1;
    int i;

    if (n <= 1)
        return 0;

    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            sum += i;
    }

    return sum == n;
}

int main(void)
{
    int num;

    printf("Enter a number: ");
    if (scanf("%d", &num) != 1)
        return 0;

    if (isPerfect(num))
        printf("%d is a perfect number.\n", num);
    else
        printf("%d is not a perfect number.\n", num);

    return 0;
}
