#include <stdio.h>

int main() {
    int num;
    int bits[32];
    int i = 0;

    printf("Enter a decimal number: ");
    if (scanf("%d", &num) != 1) {
        return 0;
    }

    if (num == 0) {
        printf("0\n");
        return 0;
    }

    while (num > 0) {
        bits[i++] = num % 2;
        num /= 2;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bits[j]);
    }
    printf("\n");

    return 0;
}
