#include <stdio.h>

int main(void)
{
    int n;
    int a[100];

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int max_count = 0;
    int value = a[0];

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            value = a[i];
        }
    }

    printf("Maximum frequency element: %d\n", value);
    printf("Frequency: %d\n", max_count);
    return 0;
}
