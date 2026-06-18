#include <stdio.h>

int main(void)
{
    int n, sum;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target sum: ");
    if (scanf("%d", &sum) != 1)
        return 0;

    int found = 0;
    for (int i = 0; i < n - 1 && !found; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == sum) {
                printf("Pair found: %d %d\n", arr[i], arr[j]);
                found = 1;
                break;
            }
        }
    }

    if (!found)
        printf("No pair with given sum.\n");

    return 0;
}
