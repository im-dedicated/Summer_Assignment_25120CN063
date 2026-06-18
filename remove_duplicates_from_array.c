#include <stdio.h>

int main(void)
{
    int n, i, j, k;
    int a[100];

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1)
        return 0;
    if (n > 100)
        n = 100;

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n;) {
            if (a[j] == a[i]) {
                for (k = j; k < n - 1; k++)
                    a[k] = a[k + 1];
                n--;
            } else {
                j++;
            }
        }
    }

    printf("Array without duplicates:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
