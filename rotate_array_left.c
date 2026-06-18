#include <stdio.h>

int main() {
    int n, d;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter rotation count: ");
    scanf("%d", &d);
    d = d % n;

    printf("Rotated array:\n");
    for (int i = 0; i < n; i++) {
        int idx = (i + d) % n;
        printf("%d ", a[idx]);
    }
    printf("\n");
    return 0;
}
