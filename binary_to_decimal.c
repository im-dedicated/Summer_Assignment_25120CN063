#include <stdio.h>
#include <string.h>

int main() {
    char bin[65];
    int i, len;
    long decimal = 0;

    printf("Enter a binary number: ");
    scanf("%64s", bin);

    len = strlen(bin);
    for (i = 0; i < len; i++) {
        if (bin[i] != '0' && bin[i] != '1') {
            printf("Invalid binary number\n");
            return 1;
        }
        decimal = decimal * 2 + (bin[i] - '0');
    }

    printf("Decimal value: %ld\n", decimal);
    return 0;
}
