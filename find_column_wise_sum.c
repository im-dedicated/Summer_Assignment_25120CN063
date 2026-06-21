#include <stdio.h>

int main(void)
{
    int rows, cols;
    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2)
        return 0;

    int mat[100][100];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += mat[i][j];
        }
        printf("Sum of column %d = %d\n", j + 1, sum);
    }

    return 0;
}
