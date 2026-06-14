#include <stdio.h>

int main(void)
{
    int arr[100];
    int n, i, target, frequency = 0;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter element to count: ");
    scanf("%d", &target);

    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            frequency++;
        }
    }

    printf("%d occurs %d time%s\n", target, frequency,
           frequency == 1 ? "" : "s");
    return 0;
}
