#include <stdio.h>

int main() {
    int rows, i, j;

    printf("Enter number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0)
        return 0;

    for (i = rows; i >= 1; i--) {
        for (j = 1; j <= rows - i; j++)
            printf(" ");
        for (j = 1; j <= 2 * i - 1; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}
