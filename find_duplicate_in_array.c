#include <stdio.h>

int main(void)
{
    int n, i, j;
    int found;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    int a[n];

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Duplicate elements:\n");
    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                found = 1;
                break;
            }
        }
        if (found)
            continue;

        for (j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                printf("%d\n", a[i]);
                break;
            }
        }
    }

    return 0;
}
