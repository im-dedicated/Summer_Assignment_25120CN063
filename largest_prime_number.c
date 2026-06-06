#include <stdio.h>

int main(void)
{
    long long n;
    if (scanf("%lld", &n) != 1)
        return 0;

    if (n < 2) {
        printf("No prime factor\n");
        return 0;
    }

    long long largest = 0;

    while (n % 2 == 0) {
        largest = 2;
        n /= 2;
    }

    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
    }

    if (n > 1)
        largest = n;

    printf("%lld\n", largest);
    return 0;
}
