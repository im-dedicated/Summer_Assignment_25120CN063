#include <stdio.h>

int main() {
    int n;
    int i;
    int largest, second;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Need at least two numbers\n");
        return 0;
    }

    int a[n];
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    largest = second = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] > largest) {
            second = largest;
            largest = a[i];
        } else if (a[i] > second && a[i] != largest) {
            second = a[i];
        }
    }

    if (largest == second) {
        printf("No second largest element\n");
    } else {
        printf("Second largest element is %d\n", second);
    }

    return 0;
}
