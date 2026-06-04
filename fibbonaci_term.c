#include <stdio.h>

int main() {
    int n;
    long long a = 0, b = 1, next;

    printf("Enter the position of the Fibonacci term: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    if (n == 1) {
        printf("Fibonacci term %d = %lld\n", n, a);
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }

    printf("Fibonacci term %d = %lld\n", n, a);
    return 0;
}
