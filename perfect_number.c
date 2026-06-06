#include <stdio.h>

int main(void) {
	int num, i, sum = 0;

	printf("Enter a positive integer: ");
	if (scanf("%d", &num) != 1) {
		printf("Invalid input.\n");
		return 1;
	}

	if (num <= 0) {
		printf("Please enter a positive integer.\n");
		return 1;
	}

	for (i = 1; i <= num / 2; ++i) {
		if (num % i == 0) {
			sum += i;
		}
	}

	if (sum == num) {
		printf("%d is a perfect number.\n", num);
	} else {
		printf("%d is not a perfect number.\n", num);
	}

	return 0;
}
