#include <stdio.h>

int main() {
    int n, i, j;
    int sum = 0;

    printf("Enter size of matrix: ");
    scanf("%d", &n);

    int a[n][n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        sum += a[i][i];
        if (i != n - 1 - i) {
            sum += a[i][n - 1 - i];
        }
    }

    printf("Diagonal sum = %d\n", sum);
    return 0;
}
