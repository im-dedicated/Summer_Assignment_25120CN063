#include <stdio.h>

int main(void)
{
    int n, a[10][10];
    int i, j, symmetric = 1;

    if (scanf("%d", &n) != 1)
        return 0;
    if (n <= 0 || n > 10)
        return 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return 0;

    for (i = 0; i < n && symmetric; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                symmetric = 0;
                break;
            }
        }
    }

    if (symmetric)
        printf("The matrix is symmetric.\n");
    else
        printf("The matrix is not symmetric.\n");

    return 0;
}
