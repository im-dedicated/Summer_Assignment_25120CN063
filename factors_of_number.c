#include <stdio.h>

int main() {
    int n, i;

    printf("Enter a number: ");
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    printf("Factors of %d are:\n", n);
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
