#include <stdio.h>

int main(void)
{
    int rows, i, j;
    printf("Enter number of rows: ");
    if (scanf("%d", &rows) != 1)
        return 1;

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}
