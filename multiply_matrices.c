#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int r1, c1, r2, c2;
    int i, j, k;

    printf("Enter rows and columns of first matrix: ");
    if (scanf("%d %d", &r1, &c1) != 2) return 0;
    printf("Enter rows and columns of second matrix: ");
    if (scanf("%d %d", &r2, &c2) != 2) return 0;

    if (c1 != r2) {
        printf("Matrices cannot be multiplied (incompatible dimensions)\n");
        return 0;
    }

    int a[r1][c1];
    int b[r2][c2];
    int res[r1][c2];

    printf("Enter elements of first matrix (%d values):\n", r1*c1);
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c1; ++j)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix (%d values):\n", r2*c2);
    for (i = 0; i < r2; ++i)
        for (j = 0; j < c2; ++j)
            scanf("%d", &b[i][j]);

    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j) {
            res[i][j] = 0;
            for (k = 0; k < c1; ++k)
                res[i][j] += a[i][k] * b[k][j];
        }

    printf("Resultant matrix (%dx%d):\n", r1, c2);
    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j)
            printf("%d ", res[i][j]);
        printf("\n");
    }

    return 0;
}
