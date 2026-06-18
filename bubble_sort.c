#include <stdio.h>

int main(void)
{
	int n, i, j, temp;
	int a[100];

	printf("Enter number of elements (max 100): ");
	if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
		printf("Invalid size\n");
		return 1;
	}

	for (i = 0; i < n; i++) {
		printf("Enter element %d: ", i + 1);
		scanf("%d", &a[i]);
	}

	/* Bubble sort */
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	printf("Sorted array: \n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
