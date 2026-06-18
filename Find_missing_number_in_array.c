#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter the value of n (array should contain numbers from 1 to n with one missing): ");
    if (scanf("%d", &n) != 1 || n <= 1) {
        return 0;
    }

    int arr[n - 1];
    printf("Enter %d numbers:\n", n - 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }

    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += arr[i];
    }

    printf("Missing number is %d\n", total - sum);
    return 0;
}
