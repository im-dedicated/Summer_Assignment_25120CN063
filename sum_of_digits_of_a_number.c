#include <stdio.h>
#include <stdlib.h>
int main() {
	long n;
	int sum = 0;

	printf("Enter an integer: ");

	if (scanf("%ld", &n) != 1) {
		printf("Invalid input.\n");
		return 1;
	}

	n = labs(n);

	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	printf("Sum of the digits: %d\n", sum);
	return 0;
}
