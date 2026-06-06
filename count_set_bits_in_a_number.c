#include <stdio.h>

int main(void)
{
    unsigned int n;
    int count = 0;

    printf("Enter a number: ");
    if (scanf("%u", &n) != 1) {
        return 1;
    }

    while (n) {
        count += n & 1;
        n >>= 1;
    }

    printf("Number of set bits: %d\n", count);
    return 0;
}
